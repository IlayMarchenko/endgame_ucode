#include "game.h"

void enemy4(WINDOW **term){
	if(enem4.flag == false){
		enem4.y2 = 2;
		enem4.x2 = rand() % ((52 - 32) + 1) + 32;
		mvwprintw(*term, enem4.y2, enem4.x2, "\\0/");
		enem4.flag = true;
		}
		if ((((shuttle.y - 2) == (enem4.y2 + enem4.n1)) && ((shuttle.x) == enem4.x2))
			|| (((shuttle.y - 1) == (enem4.y2 + enem4.n1)) && ((shuttle.x + 1) == enem4.x2))
			|| (((shuttle.y - 1) == (enem4.y2 + enem4.n1)) && ((shuttle.x + 2) == enem4.x2))
			|| (((shuttle.y - 1) == (enem4.y2 + enem4.n1)) && ((shuttle.x + 3) == enem4.x2))
			|| (((shuttle.y - 1) == (enem4.y2 + enem4.n1)) && ((shuttle.x + 4) == enem4.x2))){
			mvwprintw(*term, enem4.y2 + enem4.n - 1, enem4.x2, "   ");
					enem4.n = 1;
					enem4.n1 = 0;
					enem4.flag = false;
					score.lives--;
		}
		if ((((shuttle.y - 1) == (enem4.y2 + enem4.n1)) && ((shuttle.x - 3) == enem4.x2 + 2))
			|| (((shuttle.y - 1) == (enem4.y2 + enem4.n1)) && ((shuttle.x - 2) == enem4.x2 + 2))
			|| (((shuttle.y - 1) == (enem4.y2 + enem4.n1)) && ((shuttle.x - 1) == enem4.x2 + 2))
			|| (((shuttle.y - 2) == (enem4.y2 + enem4.n1)) && ((shuttle.x) == enem4.x2 + 2))
			|| (((shuttle.y - 1) == (enem4.y2 + enem4.n1)) && ((shuttle.x - 4) == enem4.x2 + 2))){
			mvwprintw(*term, enem4.y2 + enem4.n - 1, enem4.x2, "   ");
					enem4.n = 1;
					enem4.n1 = 0;
					enem4.flag = false;
					score.lives--;
		}
		if((((shots.y - shots.n + 1) == (enem4.y2 + enem4.n)) && (shots.x == enem4.x2))
			|| (((shots.y - shots.n + 1) == (enem4.y2 + enem4.n)) && (shots.x == enem4.x2 + 1))
			|| (((shots.y - shots.n + 1) == (enem4.y2 + enem4.n)) && (shots.x == enem4.x2 + 2))
			|| (((shots.y - shots.n + 1) == (enem4.y2 + enem4.n)) && (shots.x == enem4.x2 - 1))
			|| (((shots.y - shots.n + 1) == (enem4.y2 + enem4.n)) && (shots.x == enem4.x2 - 2))){
					mvwprintw(*term, enem4.y2 + enem4.n - 1, enem4.x2, "   ");
					enem4.n = 1;
					enem4.n1 = 0;
					enem4.flag = false;
					mvwprintw(*term, shots.y - shots.n + 1, shots.x, "   ");
					shots.n = 1;
					shots.n1 = 0;
					shots.flag = true;
					score.scorenem++;
					
		}
		else {
			enem4.count++;
			if(enem4.count == (27000 / score.lvl)){
				enem4.count = 0;
				mvwprintw(*term, enem4.y2 + enem4.n, enem4.x2, "\\0/");
				mvwprintw(*term, enem4.y2 + enem4.n1, enem4.x2, "   ");
				enem4.n++;
				enem4.n1++;
				if(enem4.n == 48){
					mvwprintw(*term, enem4.y2 + enem4.n - 1, enem4.x2, "   ");
				enem4.n = 1;
				enem4.n1 = 0;
				enem4.flag = false;
				}
			}
		}
}
