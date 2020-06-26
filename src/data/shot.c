#include "game.h"

void shot(WINDOW **term){
		if(shots.flag == true){
			shots.x = shuttle.x;
            shots.y = shuttle.y;
		}
		if (shots.flag == false){
			shots.count++;
			if(shots.count == (4000 / score.speedshot)){
				shots.count = 0;
				mvwprintw(*term, shots.y - shots.n, shots.x, "(*)");
				mvwprintw(*term, shots.y - shots.n1, shots.x, "   ");
				shots.n++;
				shots.n1++;
				if(map.map[shots.y - shots.n - 1][shots.x] == '-'){
					mvwprintw(*term, shots.y - shots.n + 1, shots.x, "   ");
				shots.n = 1;
				shots.n1 = 0;
				shots.flag = true;
				shots.count = 0;
				}
			}
		}
}
