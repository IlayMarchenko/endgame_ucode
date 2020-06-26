#include "game.h"

void shuttlef(WINDOW **term) {
    wattron(*term, COLOR_PAIR(BG_RED));
    mvwprintw(*term, shuttle.y, shuttle.x - 3, "_");

    wattron(*term, COLOR_PAIR(BG_WHITE));
    mvwprintw(*term, shuttle.y, shuttle.x, "I");

    wattron(*term, COLOR_PAIR(BG_RED));
    mvwprintw(*term, shuttle.y, shuttle.x + 3, "_");

    wattron(*term, COLOR_PAIR(BG_RED));
    mvwprintw(*term, shuttle.y + 1, shuttle.x - 4, "/_\\");
    mvwprintw(*term, shuttle.y + 1, shuttle.x + 2, "/_\\");
    wattron(*term, COLOR_PAIR(BG_WHITE));
    mvwprintw(*term, shuttle.y + 1, shuttle.x - 1, "/T\\");

    wattron(*term, COLOR_PAIR(BG_WHITE));
    mvwprintw(*term, shuttle.y + 2, shuttle.x - 4, "|_/___\\_|");
    wattron(*term, COLOR_PAIR(BG_YELLOW));
    mvwprintw(*term, shuttle.y + 3, shuttle.x - 1, "III");

    wattrset(*term, 0);
    wrefresh(*term);
}
