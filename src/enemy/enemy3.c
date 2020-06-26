#include "game.h"

void enemy3(WINDOW **term){
if(enem3.flag == false){
		enem3.y2 = 2;
		enem3.x2 = rand() % ((52 - 32) + 1) + 32;
		mvwprintw(*term, enem3.y2, enem3.x2, "\\0/");
		enem3.flag = true;
		}
		if ((((shuttle.y - 2) == (enem3.y2 + enem3.n1)) && ((shuttle.x) == enem3.x2))
			|| (((shuttle.y - 1) == (enem3.y2 + enem3.n1)) && ((shuttle.x + 1) == enem3.x2))
			|| (((shuttle.y - 1) == (enem3.y2 + enem3.n1)) && ((shuttle.x + 2) == enem3.x2))
			|| (((shuttle.y - 1) == (enem3.y2 + enem3.n1)) && ((shuttle.x + 3) == enem3.x2))
			|| (((shuttle.y - 1) == (enem3.y2 + enem3.n1)) && ((shuttle.x + 4) == enem3.x2))){
			mvwprintw(*term, enem3.y2 + enem3.n - 1, enem3.x2, "   ");
					enem3.n = 1;
					enem3.n1 = 0;
					enem3.flag = false;
					score.lives--;
		}
		if ((((shuttle.y - 1) == (enem3.y2 + enem3.n1)) && ((shuttle.x - 3) == enem3.x2 + 2))
			|| (((shuttle.y - 1) == (enem3.y2 + enem3.n1)) && ((shuttle.x - 2) == enem3.x2 + 2))
			|| (((shuttle.y - 1) == (enem3.y2 + enem3.n1)) && ((shuttle.x - 1) == enem3.x2 + 2))
			|| (((shuttle.y - 2) == (enem3.y2 + enem3.n1)) && ((shuttle.x) == enem3.x2 + 2))
			|| (((shuttle.y - 1) == (enem3.y2 + enem3.n1)) && ((shuttle.x - 4) == enem3.x2 + 2))){
			mvwprintw(*term, enem3.y2 + enem3.n - 1, enem3.x2, "   ");
					enem3.n = 1;
					enem3.n1 = 0;
					enem3.flag = false;
					score.lives--;
		}
		if((((shots.y - shots.n + 1) == (enem3.y2 + enem3.n)) && (shots.x == enem3.x2))
			|| (((shots.y - shots.n + 1) == (enem3.y2 + enem3.n)) && (shots.x == enem3.x2 + 1))
			|| (((shots.y - shots.n + 1) == (enem3.y2 + enem3.n)) && (shots.x == enem3.x2 + 2))
			|| (((shots.y - shots.n + 1) == (enem3.y2 + enem3.n)) && (shots.x == enem3.x2 - 1))
			|| (((shots.y - shots.n + 1) == (enem3.y2 + enem3.n)) && (shots.x == enem3.x2 - 2))){
					mvwprintw(*term, enem3.y2 + enem3.n - 1, enem3.x2, "   ");
					enem3.n = 1;
					enem3.n1 = 0;
					enem3.flag = false;
					mvwprintw(*term, shots.y - shots.n + 1, shots.x, "   ");
					shots.n = 1;
					shots.n1 = 0;
					shots.flag = true;
					score.scorenem++;
					
		}
		else {
			enem3.count++;
			if(enem3.count == (24000 / score.lvl)){
				enem3.count = 0;
				mvwprintw(*term, enem3.y2 + enem3.n, enem3.x2, "\\0/");
				mvwprintw(*term, enem3.y2 + enem3.n1, enem3.x2, "   ");
				enem3.n++;
				enem3.n1++;
				if(enem3.n == 48){
					mvwprintw(*term, enem3.y2 + enem3.n - 1, enem3.x2, "   ");
				enem3.n = 1;
				enem3.n1 = 0;
				enem3.flag = false;
				}
			}
		}
}
