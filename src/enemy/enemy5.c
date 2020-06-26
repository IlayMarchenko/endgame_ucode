#include "game.h"

void enemy5(WINDOW **term){
		if(enem5.flag == false){
		enem5.y2 = 2;
		enem5.x2 = rand() % ((52 - 32) + 1) + 32;
		mvwprintw(*term, enem5.y2, enem5.x2, "\\0/");
		enem5.flag = true;
		}
		if ((((shuttle.y - 2) == (enem5.y2 + enem5.n1)) && ((shuttle.x) == enem5.x2))
			|| (((shuttle.y - 1) == (enem5.y2 + enem5.n1)) && ((shuttle.x + 1) == enem5.x2))
			|| (((shuttle.y - 1) == (enem5.y2 + enem5.n1)) && ((shuttle.x + 2) == enem5.x2))
			|| (((shuttle.y - 1) == (enem5.y2 + enem5.n1)) && ((shuttle.x + 3) == enem5.x2))
			|| (((shuttle.y - 1) == (enem5.y2 + enem5.n1)) && ((shuttle.x + 4) == enem5.x2))){
			mvwprintw(*term, enem5.y2 + enem5.n - 1, enem5.x2, "   ");
					enem5.n = 1;
					enem5.n1 = 0;
					enem5.flag = false;
					score.lives--;
		}
		if ((((shuttle.y - 1) == (enem5.y2 + enem5.n1)) && ((shuttle.x - 3) == enem5.x2 + 2))
			|| (((shuttle.y - 1) == (enem5.y2 + enem5.n1)) && ((shuttle.x - 2) == enem5.x2 + 2))
			|| (((shuttle.y - 1) == (enem5.y2 + enem5.n1)) && ((shuttle.x - 1) == enem5.x2 + 2))
			|| (((shuttle.y - 2) == (enem5.y2 + enem5.n1)) && ((shuttle.x) == enem5.x2 + 2))
			|| (((shuttle.y - 1) == (enem5.y2 + enem5.n1)) && ((shuttle.x - 4) == enem5.x2 + 2))){
			mvwprintw(*term, enem5.y2 + enem5.n - 1, enem5.x2, "   ");
					enem5.n = 1;
					enem5.n1 = 0;
					enem5.flag = false;
					score.lives--;
		}
		if((((shots.y - shots.n + 1) == (enem5.y2 + enem5.n)) && (shots.x == enem5.x2))
			|| (((shots.y - shots.n + 1) == (enem5.y2 + enem5.n)) && (shots.x == enem5.x2 + 1))
			|| (((shots.y - shots.n + 1) == (enem5.y2 + enem5.n)) && (shots.x == enem5.x2 + 2))
			|| (((shots.y - shots.n + 1) == (enem5.y2 + enem5.n)) && (shots.x == enem5.x2 - 1))
			|| (((shots.y - shots.n + 1) == (enem5.y2 + enem5.n)) && (shots.x == enem5.x2 - 2))){
					mvwprintw(*term, enem5.y2 + enem5.n - 1, enem5.x2, "   ");
					enem5.n = 1;
					enem5.n1 = 0;
					enem5.flag = false;
					mvwprintw(*term, shots.y - shots.n + 1, shots.x, "   ");
					shots.n = 1;
					shots.n1 = 0;
					shots.flag = true;
					score.scorenem++;
					
		}
		else {
			enem5.count++;
			if(enem5.count == (20000 / score.lvl)){
				enem5.count = 0;
				mvwprintw(*term, enem5.y2 + enem5.n, enem5.x2, "\\0/");
				mvwprintw(*term, enem5.y2 + enem5.n1, enem5.x2, "   ");
				enem5.n++;
				enem5.n1++;
				if(enem5.n == 48){
					mvwprintw(*term, enem5.y2 + enem5.n - 1, enem5.x2, "   ");
				enem5.n = 1;
				enem5.n1 = 0;
				enem5.flag = false;
				}
			}
		}
}
