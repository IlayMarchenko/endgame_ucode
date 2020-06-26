#include "game.h"

void game_info(WINDOW **term){
		mvwprintw(*term, 51, 13, "lives : ");
        mvwprintw(*term, 51, 21, "%d", score.lives);
        if (score.lives == 5)
        	mvwprintw(*term, 51, 23, "MAX");
        if (score.lives < 5)
        	mvwprintw(*term, 51, 23, "   ");
        mvwprintw(*term, 52, 13, "kills : ");
        mvwprintw(*term, 52, 21, "%d", score.scorenem);

        mvwprintw(*term, 51, 65, "game level : ");
        mvwprintw(*term, 51, 78, "%d", score.lvl);
        mvwprintw(*term, 52, 59, "speed of shuttle : ", score.speed);
        mvwprintw(*term, 52, 78, "%d", score.speed);
}
