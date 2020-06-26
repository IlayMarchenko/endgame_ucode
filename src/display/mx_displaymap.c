#include "game.h"

void mx_displaymap(WINDOW **term) {
    for (int row = 0; row < 53; row++) {
        for (int col = 0; col < 90; col++) {
            if (map.map[row][col] != ' ') {
                wattron(*term, COLOR_PAIR(BGR_GREEN));
                mvwaddch(*term, row + 1, col + 1, map.map[row][col]);
                wattroff(*term, COLOR_PAIR(BGR_GREEN));
            }
        }
    }

    for (int row = 0; row < 53; row++) {
        for (int col = 0; col < 90; col++) {
            if (map.map[row][col] == ' ') {
                wattron(*term, COLOR_PAIR(BG_WHITE));
                mvwaddch(*term, row + 1, col + 1, map.map[row][col]);
                wattroff(*term, COLOR_PAIR(BG_WHITE));
                if (col == 78) {
                    wrefresh(*term);
                }
                usleep(50);
            }
        }
    }
}

