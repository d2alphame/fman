#include <ncurses.h>

int main(void) {
    initscr();              // Initialize ncurses
    addstr("Goodbye, cruel C programming!");
    refresh();

    getch();
    endwin();               // Properly close ncurses
    return 0;               // Return with success
}