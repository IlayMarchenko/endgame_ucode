#include "game.h"

void enemy(WINDOW **term){
		if(enem1.flag == false){
		enem1.y2 = 2;
		enem1.x2 = rand() % ((34 - 12) + 1) + 12;
		mvwprintw(*term, enem1.y2, enem1.x2, "\\0/");
		enem1.flag = true;
		}
		if (((((shuttle.y - 2) == (enem1.y2 + enem1.n1)) && ((shuttle.x) == enem1.x2))
			|| (((shuttle.y - 1) == (enem1.y2 + enem1.n1)) && ((shuttle.x + 1) == enem1.x2))
			|| (((shuttle.y - 1) == (enem1.y2 + enem1.n1)) && ((shuttle.x + 2) == enem1.x2))
			|| (((shuttle.y - 1) == (enem1.y2 + enem1.n1)) && ((shuttle.x + 3) == enem1.x2))
			|| (((shuttle.y - 1) == (enem1.y2 + enem1.n1)) && ((shuttle.x + 4) == enem1.x2)))) {
			mvwprintw(*term, enem1.y2 + enem1.n - 1, enem1.x2, "   ");
					enem1.n = 1;
					enem1.n1 = 0;
					enem1.flag = false;
					score.lives--;
		}
		if ((((shuttle.y - 1) == (enem1.y2 + enem1.n1)) && ((shuttle.x - 3) == enem1.x2 + 2))
			|| (((shuttle.y - 1) == (enem1.y2 + enem1.n1)) && ((shuttle.x - 2) == enem1.x2 + 2))
			|| (((shuttle.y - 1) == (enem1.y2 + enem1.n1)) && ((shuttle.x - 1) == enem1.x2))
			|| (((shuttle.y - 2) == (enem1.y2 + enem1.n1)) && ((shuttle.x) == enem1.x2 + 2))
			|| (((shuttle.y - 1) == (enem1.y2 + enem1.n1)) && ((shuttle.x - 4) == enem1.x2 + 2))) {
			mvwprintw(*term, enem1.y2 + enem1.n - 1, enem1.x2, "   ");
					enem1.n = 1;
					enem1.n1 = 0;
					enem1.flag = false;
					score.lives--;
		}
		if((((shots.y - shots.n + 1) == (enem1.y2 + enem1.n)) && (shots.x == enem1.x2))
			|| (((shots.y - shots.n + 1) == (enem1.y2 + enem1.n)) && (shots.x == enem1.x2 + 1))
			|| (((shots.y - shots.n + 1) == (enem1.y2 + enem1.n)) && (shots.x == enem1.x2 + 2))
			|| (((shots.y - shots.n + 1) == (enem1.y2 + enem1.n)) && (shots.x == enem1.x2 - 1))
			|| (((shots.y - shots.n + 1) == (enem1.y2 + enem1.n)) && (shots.x == enem1.x2 - 2))){
					mvwprintw(*term, enem1.y2 + enem1.n - 1, enem1.x2, "   ");
					enem1.n = 1;
					enem1.n1 = 0;
					enem1.flag = false;
					mvwprintw(*term, shots.y - shots.n + 1, shots.x, "   ");
					shots.n = 1;
					shots.n1 = 0;
					shots.flag = true;
					score.scorenem++;
					
		}
		else {
			enem1.count++;
			if(enem1.count == (22000 / score.lvl)){
				enem1.count = 0;
				mvwprintw(*term, enem1.y2 + enem1.n, enem1.x2, "\\0/");
				mvwprintw(*term, enem1.y2 + enem1.n1, enem1.x2, "   ");
				enem1.n++;
				enem1.n1++;
				if(enem1.n == 48){
					mvwprintw(*term, enem1.y2 + enem1.n - 1, enem1.x2, "   ");
				enem1.n = 1;
				enem1.n1 = 0;
				enem1.flag = false;
				}
			}
		}
}

