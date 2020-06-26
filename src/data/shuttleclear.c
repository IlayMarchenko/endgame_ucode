#include "game.h"

void shuttleclear(WINDOW **term){
	wattron(*term, COLOR_PAIR(BG_WHITE));
	mvwprintw(*term, shuttle.y, shuttle.x - 3, "       ");
    mvwprintw(*term, shuttle.y + 1, shuttle.x - 4, "         ");
    mvwprintw(*term, shuttle.y + 2, shuttle.x - 4, "         ");
    mvwprintw(*term, shuttle.y + 3, shuttle.x - 1, "   ");
    wattroff(*term, COLOR_PAIR(BG_WHITE));
    wrefresh(*term);
}
