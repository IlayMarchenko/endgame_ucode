#include "game.h"

void mx_startgame_clear(WINDOW **term, int x, int y);

void mx_startgame(WINDOW **term) {

    char step = '\0';
    int x = 35;
    int y = 21;
    wattron(*term, COLOR_PAIR(BG_RED));
    mvwprintw(*term, y, x,"+--------------------+");
    mvwprintw(*term, y + 1, x,"| S-P-A-C-E  W-A-R-S |");
    mvwprintw(*term, y + 2, x,"|--------------------|");
    mvwprintw(*term, y + 3, x,"|  Press S to start  |");

    mvwaddch(*term, y + 4, x, '|');
    for(int i = 0; i < 20; i++) {
        mvwaddch(*term, y + 4, 36 + i, '=');
        if (i < 4) {
            usleep(500000);
        }
        usleep(40000);

        step = getch();
        if (step != ERR) {
            while (getch() == step);
        }
        
        wrefresh(*term);
    }
    mvwaddch(*term, y + 4, x + 21, '|');

    mvwprintw(*term, y + 5, x,"+--------------------+");
    mvwprintw(*term, 51,13,"W,A,S,D - move");
    mvwprintw(*term, 52,13,"Space - shoot");

    while (1) {
        step = getch();
        if (step == 's') {
            break;
        }
        else if (step == 'S') {
            break;
        }
        else if (step == 'q') {
            endwin();
            exit(0);
        }
    }

    mx_startgame_clear(term, x, y);
    wattrset(*term, 0);
}

void mx_startgame_clear(WINDOW **term, int x, int y) {
    wattron(*term, COLOR_PAIR(BG_WHITE));
        mvwprintw(*term, y, x,"                      ");
    mvwprintw(*term, y + 1, x,"                      ");
    mvwprintw(*term, y + 2, x,"                      ");
    mvwprintw(*term, y + 3, x,"                      ");
    mvwprintw(*term, y + 4, x,"                      ");
    mvwprintw(*term, y + 5, x,"                      ");

    mvwprintw(*term, 51,13,"              ");
    mvwprintw(*term, 52,13,"             ");
}

