#include <ncurses.h>
#include <stdlib.h>

#define NEW_COLOR 1
#define RED 1000
#define GREEN 750
#define BLUE 750

void bomb(char *msg);

int main(void) {

    int max_x;
    int max_y;

    initscr();              // Initialize ncurses
    if(!has_colors()) { 
        bomb("Your terminal doesn't support colors\n");
    }
    if(start_color() != OK) {
        bomb("Could not start colors\n");
    }
    if(!can_change_color()) {
        bomb("Cannot change color");
    }

    // Colors are fine. Now we're good to go
    printw("You can use %d colors \n", COLORS);
    printw("And %d color pairs\n", COLOR_PAIRS);

    init_color(NEW_COLOR, RED, GREEN, BLUE);

    init_pair(1, NEW_COLOR, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_YELLOW);
    init_pair(3, COLOR_CYAN, COLOR_RED);
    
    bkgd(COLOR_PAIR(1));
    addstr("First color pair");
    refresh();
    getch();

    attron(COLOR_PAIR(1) | A_BOLD);
    addstr("New Color, on Black!\n");
    refresh();
    getch();

    getmaxyx(stdscr, max_y, max_x);
    printw("%d by %d\n", max_y, max_x);
    refresh();
    getch();

    endwin();               // Properly close ncurses
    return 0;               // Return with success
}

void bomb(char *msg) {
    endwin();
    puts(msg);
    exit(1);
}