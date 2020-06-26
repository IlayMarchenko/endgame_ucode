#include "game.h"

void life(WINDOW **term){
		if(lifes.flag == false){
		lifes.y2 = 2;
		lifes.x2 = rand() % ((73 - 12) + 1) + 12;
		mvwprintw(*term, lifes.y2, lifes.x2, "[+]");
		lifes.flag = true;
		}
		if ((((shuttle.y - 1) == (lifes.y2 + lifes.n1)) && ((shuttle.x - 3) == lifes.x2))
			|| (((shuttle.y - 1) == (lifes.y2 + lifes.n1)) && ((shuttle.x - 2) == lifes.x2))
			|| (((shuttle.y - 1) == (lifes.y2 + lifes.n1)) && ((shuttle.x - 1) == lifes.x2))
			|| (((shuttle.y - 1) == (lifes.y2 + lifes.n1)) && ((shuttle.x) == lifes.x2))
			|| (((shuttle.y - 1) == (lifes.y2 + lifes.n1)) && ((shuttle.x + 1) == lifes.x2))
			|| (((shuttle.y - 1) == (lifes.y2 + lifes.n1)) && ((shuttle.x + 2) == lifes.x2))
			|| (((shuttle.y - 1) == (lifes.y2 + lifes.n1)) && ((shuttle.x - 4) == lifes.x2))
			|| (((shuttle.y - 1) == (lifes.y2 + lifes.n1)) && ((shuttle.x + 3) == lifes.x2))
			|| (((shuttle.y - 1) == (lifes.y2 + lifes.n1)) && ((shuttle.x + 4) == lifes.x2))){
			mvwprintw(*term, lifes.y2 + lifes.n - 1, lifes.x2, "   ");
					lifes.n = 1;
					lifes.n1 = 0;
					lifes.flag = false;
					if(score.lives < 5)
						score.lives++;
		}
		if((((shots.y - shots.n + 1) == (lifes.y2 + lifes.n)) && (shots.x == lifes.x2))
			|| (((shots.y - shots.n + 1) == (lifes.y2 + lifes.n)) && (shots.x == lifes.x2 + 1))
			|| (((shots.y - shots.n + 1) == (lifes.y2 + lifes.n)) && (shots.x == lifes.x2 + 2))
			|| (((shots.y - shots.n + 1) == (lifes.y2 + lifes.n)) && (shots.x == lifes.x2 - 1))
			|| (((shots.y - shots.n + 1) == (lifes.y2 + lifes.n)) && (shots.x == lifes.x2 - 2))){
					mvwprintw(*term, lifes.y2 + lifes.n - 1, lifes.x2, "   ");
					lifes.n = 1;
					lifes.n1 = 0;
					lifes.flag = false;
					mvwprintw(*term, shots.y - shots.n + 1, shots.x, "   ");
					shots.n = 1;
					shots.n1 = 0;
					shots.flag = true;
		}
		else {
			lifes.count++;
			if(lifes.count == 25000){
				lifes.count = 0;
				mvwprintw(*term, lifes.y2 + lifes.n, lifes.x2, "[+]");
				mvwprintw(*term, lifes.y2 + lifes.n1, lifes.x2, "   ");
				lifes.n++;
				lifes.n1++;
				if(lifes.n == 48){
					mvwprintw(*term, lifes.y2 + lifes.n - 1, lifes.x2, "   ");
				lifes.n = 1;
				lifes.n1 = 0;
				lifes.flag = false;
				}
			}
		}
}
