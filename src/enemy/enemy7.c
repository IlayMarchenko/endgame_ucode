#include "game.h"

void enemy7(WINDOW **term){
if(enem7.flag == false){
		enem7.y2 = 2;
		enem7.x2 = rand() % ((73 - 52) + 1) + 52;
		mvwprintw(*term, enem7.y2, enem7.x2, "\\0/");
		enem7.flag = true;
		}
		if ((((shuttle.y - 2) == (enem7.y2 + enem7.n1)) && ((shuttle.x) == enem7.x2))
			|| (((shuttle.y - 1) == (enem7.y2 + enem7.n1)) && ((shuttle.x + 1) == enem7.x2))
			|| (((shuttle.y - 1) == (enem7.y2 + enem7.n1)) && ((shuttle.x + 2) == enem7.x2))
			|| (((shuttle.y - 1) == (enem7.y2 + enem7.n1)) && ((shuttle.x + 3) == enem7.x2))
			|| (((shuttle.y - 1) == (enem7.y2 + enem7.n1)) && ((shuttle.x + 4) == enem7.x2))){
			mvwprintw(*term, enem7.y2 + enem7.n - 1, enem7.x2, "   ");
					enem5.n = 1;
					enem5.n1 = 0;
					enem5.flag = false;
					score.lives--;
		}
		if ((((shuttle.y - 1) == (enem7.y2 + enem7.n1)) && ((shuttle.x - 3) == enem7.x2 + 3))
			|| (((shuttle.y - 1) == (enem7.y2 + enem7.n1)) && ((shuttle.x - 2) == enem7.x2 + 3))
			|| (((shuttle.y - 1) == (enem7.y2 + enem7.n1)) && ((shuttle.x - 1) == enem7.x2 + 3))
			|| (((shuttle.y - 2) == (enem7.y2 + enem7.n1)) && ((shuttle.x) == enem7.x2 + 3))
			|| (((shuttle.y - 1) == (enem7.y2 + enem7.n1)) && ((shuttle.x - 4) == enem7.x2 + 3))){
			mvwprintw(*term, enem7.y2 + enem7.n - 1, enem7.x2, "   ");
					enem5.n = 1;
					enem5.n1 = 0;
					enem5.flag = false;
					score.lives--;
		}
		if((((shots.y - shots.n + 1) == (enem7.y2 + enem7.n)) && (shots.x == enem7.x2))
			|| (((shots.y - shots.n + 1) == (enem7.y2 + enem7.n)) && (shots.x == enem7.x2 + 1))
			|| (((shots.y - shots.n + 1) == (enem7.y2 + enem7.n)) && (shots.x == enem7.x2 + 2))
			|| (((shots.y - shots.n + 1) == (enem7.y2 + enem7.n)) && (shots.x == enem7.x2 - 1))
			|| (((shots.y - shots.n + 1) == (enem7.y2 + enem7.n)) && (shots.x == enem7.x2 - 2))){
					mvwprintw(*term, enem7.y2 + enem7.n - 1, enem7.x2, "   ");
					enem7.n = 1;
					enem7.n1 = 0;
					enem7.flag = false;
					mvwprintw(*term, shots.y - shots.n + 1, shots.x, "   ");
					shots.n = 1;
					shots.n1 = 0;
					shots.flag = true;
					score.scorenem++;
					
		}
		else {
			enem7.count++;
			if(enem7.count == (28000 / score.lvl)){
				enem7.count = 0;
				mvwprintw(*term, enem7.y2 + enem7.n, enem7.x2, "\\0/");
				mvwprintw(*term, enem7.y2 + enem7.n1, enem7.x2, "   ");
				enem7.n++;
				enem7.n1++;
				if(enem7.n == 48){
					mvwprintw(*term, enem7.y2 + enem7.n - 1, enem7.x2, "   ");
				enem7.n = 1;
				enem7.n1 = 0;
				enem7.flag = false;
				}
			}
		}
}
