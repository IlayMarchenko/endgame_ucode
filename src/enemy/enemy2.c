#include "game.h"

void enemy2(WINDOW **term){
		if(enem2.flag == false){
		enem2.y2 = 2;
		enem2.x2 = rand() % ((34 - 12) + 1) + 12;
		mvwprintw(*term, enem2.y2, enem2.x2, "\\0/");
		enem2.flag = true;
		}
		if ((((shuttle.y - 2) == (enem2.y2 + enem2.n1)) && ((shuttle.x) == enem2.x2))
			|| (((shuttle.y - 1) == (enem2.y2 + enem2.n1)) && ((shuttle.x + 1) == enem2.x2))
			|| (((shuttle.y - 1) == (enem2.y2 + enem2.n1)) && ((shuttle.x + 2) == enem2.x2))
			|| (((shuttle.y - 1) == (enem2.y2 + enem2.n1)) && ((shuttle.x + 3) == enem2.x2))
			|| (((shuttle.y - 1) == (enem2.y2 + enem2.n1)) && ((shuttle.x + 4) == enem2.x2))){
			mvwprintw(*term, enem2.y2 + enem2.n - 1, enem2.x2, "   ");
					enem2.n = 1;
					enem2.n1 = 0;
					enem2.flag = false;
					score.lives--;
		}
		if ((((shuttle.y - 1) == (enem2.y2 + enem2.n1)) && ((shuttle.x - 3) == enem2.x2 + 2))
			|| (((shuttle.y - 1) == (enem2.y2 + enem2.n1)) && ((shuttle.x - 2) == enem2.x2 + 2))
			|| (((shuttle.y - 1) == (enem2.y2 + enem2.n1)) && ((shuttle.x - 1) == enem2.x2 + 2))
			|| (((shuttle.y - 2) == (enem2.y2 + enem2.n1)) && ((shuttle.x) == enem2.x2 + 2))
			|| (((shuttle.y - 1) == (enem2.y2 + enem2.n1)) && ((shuttle.x - 4) == enem2.x2 + 2))){
			mvwprintw(*term, enem2.y2 + enem2.n - 1, enem2.x2, "   ");
					enem2.n = 1;
					enem2.n1 = 0;
					enem2.flag = false;
					score.lives--;
		}
		if((((shots.y - shots.n + 1) == (enem2.y2 + enem2.n)) && (shots.x == enem2.x2))
			|| (((shots.y - shots.n + 1) == (enem2.y2 + enem2.n)) && (shots.x == enem2.x2 + 1))
			|| (((shots.y - shots.n + 1) == (enem2.y2 + enem2.n)) && (shots.x == enem2.x2 + 2))
			|| (((shots.y - shots.n + 1) == (enem2.y2 + enem2.n)) && (shots.x == enem2.x2 - 1))
			|| (((shots.y - shots.n + 1) == (enem2.y2 + enem2.n)) && (shots.x == enem2.x2 - 2))){
					mvwprintw(*term, enem2.y2 + enem2.n - 1, enem2.x2, "   ");
					enem2.n = 1;
					enem2.n1 = 0;
					enem2.flag = false;
					mvwprintw(*term, shots.y - shots.n + 1, shots.x, "   ");
					shots.n = 1;
					shots.n1 = 0;
					shots.flag = true;
					score.scorenem++;
					
		}
		else {
			enem2.count++;
			if(enem2.count == (18000 / score.lvl)){
				enem2.count = 0;
				mvwprintw(*term, enem2.y2 + enem2.n, enem2.x2, "\\0/");
				mvwprintw(*term, enem2.y2 + enem2.n1, enem2.x2, "   ");
				enem2.n++;
				enem2.n1++;
				if(enem2.n == 48){
					mvwprintw(*term, enem2.y2 + enem2.n - 1, enem2.x2, "   ");
				enem2.n = 1;
				enem2.n1 = 0;
				enem2.flag = false;
				}
			}
		}
}
