#include "game.h"

void game_status(WINDOW **term){
	if (score.scorenem == 10 || score.scorenem == 20 || score.scorenem == 30 || score.scorenem == 40 || score.scorenem == 50 || score.scorenem == 60){
		score.lvl = score.scorenem / 10 + 1;
		enem1.count = 0;
		enem2.count = 0;
		enem3.count = 0;
		enem4.count = 0;
		enem5.count = 0;
		enem6.count = 0;
		enem7.count = 0;
		lifes.count = 0;
		lifes.flag = true;
		wattron(*term, COLOR_PAIR(BG_RED));
		mvwprintw(*term, 51, 34, "Are you ready?");
		mvwprintw(*term, 52, 30, "Kill someone to continue");
		wattrset(*term, 0);
	}
	if (score.scorenem == 10 || score.scorenem == 20){
		score.speed = score.scorenem / 10 + 1;
	}
	if (score.scorenem == 20 || score.scorenem == 40){
		score.speedshot = score.scorenem / 10;
	}
	if (score.scorenem == 11 || score.scorenem == 21 || score.scorenem == 31 || score.scorenem == 41 || score.scorenem == 51 || score.scorenem == 61){
		wattron(*term, COLOR_PAIR(BG_WHITE));
		mvwprintw(*term, 51, 34, "                ");
		mvwprintw(*term, 52, 30, "                        ");
		wattroff(*term, COLOR_PAIR(BG_WHITE));
	}
	if (score.lives == 0){
        record(score.scorenem);
		mx_gameover(term);
		endwin();
		exit(0);
	}
}
