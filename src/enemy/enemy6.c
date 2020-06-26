#include "game.h"

void enemy6(WINDOW **term){
if(enem6.flag == false){
		enem6.y2 = 2;
		enem6.x2 = rand() % ((73 - 52) + 1) + 52;
		mvwprintw(*term, enem6.y2, enem6.x2, "\\0/");
		enem6.flag = true;
		}
		if ((((shuttle.y - 2) == (enem6.y2 + enem6.n1)) && ((shuttle.x) == enem6.x2))
			|| (((shuttle.y - 1) == (enem6.y2 + enem6.n1)) && ((shuttle.x + 1) == enem6.x2))
			|| (((shuttle.y - 1) == (enem6.y2 + enem6.n1)) && ((shuttle.x + 2) == enem6.x2))
			|| (((shuttle.y - 1) == (enem6.y2 + enem6.n1)) && ((shuttle.x + 3) == enem6.x2))
			|| (((shuttle.y - 1) == (enem6.y2 + enem6.n1)) && ((shuttle.x + 4) == enem6.x2))){
			mvwprintw(*term, enem6.y2 + enem6.n - 1, enem6.x2, "   ");
					enem6.n = 1;
					enem6.n1 = 0;
					enem6.flag = false;
					score.lives--;
		}
		if ((((shuttle.y - 1) == (enem6.y2 + enem6.n1)) && ((shuttle.x - 3) == enem6.x2 + 2))
			|| (((shuttle.y - 1) == (enem6.y2 + enem6.n1)) && ((shuttle.x - 2) == enem6.x2 + 2))
			|| (((shuttle.y - 1) == (enem6.y2 + enem6.n1)) && ((shuttle.x - 1) == enem6.x2 + 2))
			|| (((shuttle.y - 2) == (enem6.y2 + enem6.n1)) && ((shuttle.x) == enem6.x2 + 2))
			|| (((shuttle.y - 1) == (enem6.y2 + enem6.n1)) && ((shuttle.x - 4) == enem6.x2 + 2))){
			mvwprintw(*term, enem6.y2 + enem6.n - 1, enem6.x2, "   ");
					enem6.n = 1;
					enem6.n1 = 0;
					enem6.flag = false;
					score.lives--;
		}
		if((((shots.y - shots.n + 1) == (enem6.y2 + enem6.n)) && (shots.x == enem6.x2))
			|| (((shots.y - shots.n + 1) == (enem6.y2 + enem6.n)) && (shots.x == enem6.x2 + 1))
			|| (((shots.y - shots.n + 1) == (enem6.y2 + enem6.n)) && (shots.x == enem6.x2 + 2))
			|| (((shots.y - shots.n + 1) == (enem6.y2 + enem6.n)) && (shots.x == enem6.x2 - 1))
			|| (((shots.y - shots.n + 1) == (enem6.y2 + enem6.n)) && (shots.x == enem6.x2 - 2))){
					mvwprintw(*term, enem6.y2 + enem6.n - 1, enem6.x2, "   ");
					enem6.n = 1;
					enem6.n1 = 0;
					enem6.flag = false;
					mvwprintw(*term, shots.y - shots.n + 1, shots.x, "   ");
					shots.n = 1;
					shots.n1 = 0;
					shots.flag = true;
					score.scorenem++;
					
		}
		else {
			enem6.count++;
			if(enem6.count == (16000 / score.lvl)){
				enem6.count = 0;
				mvwprintw(*term, enem6.y2 + enem6.n, enem6.x2, "\\0/");
				mvwprintw(*term, enem6.y2 + enem6.n1, enem6.x2, "   ");
				enem6.n++;
				enem6.n1++;
				if(enem6.n == 48){
					mvwprintw(*term, enem6.y2 + enem6.n - 1, enem6.x2, "   ");
				enem6.n = 1;
				enem6.n1 = 0;
				enem6.flag = false;
				}
			}
		}
}
