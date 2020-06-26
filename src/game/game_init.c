#include "game.h"

void game_init(void){
	enem1.n = 1;
    enem1.n1 = 0;
    enem1.count = 0;
    enem1.flag = false;

    enem2.n = 1;
    enem2.n1 = 0;
    enem2.count = 0;
    enem2.flag = false;

    enem3.n = 1;
    enem3.n1 = 0;
    enem3.count = 0;
    enem3.flag = false;

    enem4.n = 1;
    enem4.n1 = 0;
    enem4.count = 0;
    enem4.flag = false;

    enem5.n = 1;
    enem5.n1 = 0;
    enem5.count = 0;
    enem5.flag = false;

    enem6.n = 1;
    enem6.n1 = 0;
    enem6.count = 0;
    enem6.flag = false;

    enem7.n = 1;
    enem7.n1 = 0;
    enem7.count = 0;
    enem7.flag = false;

    shuttle.x = 40;
    shuttle.y = 40;

    shots.flag = true;
    shots.count = 0;
    shots.n = 1;
    shots.n1 = 0;

    score.lives = 3;
    score.scorenem = 0;
    score.lvl = 1;
    score.speed = 1;
    score.speedshot = 1;

    lifes.n = 1;
    lifes.n1 = 0;
    lifes.count = 0;
    lifes.flag = false;
}
