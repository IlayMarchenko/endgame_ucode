#include "game.h"

int main(void) {
    WINDOW *term;
    mx_init_screen(&term);
    init_map();
    game_init();
    mx_displaymap(&term);
    mx_startgame(&term);

    srand(time(0));
    char move = '\0';
    while (move != 'q') {
        shuttlef(&term);
        move = getch();
        game_status(&term);
        wattron(term, COLOR_PAIR(BG_YELLOW));
        enemy(&term);
        enemy2(&term);
        enemy3(&term);
        enemy4(&term);
        enemy5(&term);
        enemy6(&term);
        enemy7(&term);
        wattron(term, COLOR_PAIR(BG_GREEN));
        shot(&term);
        wattron(term, COLOR_PAIR(BG_RED));
        life(&term);
        wattron(term, COLOR_PAIR(BG_WHITE));
        game_info(&term);
        wattrset(term, 0);
       switch (move) {
        case UP:
            if (map.map[shuttle.y - 2][shuttle.x] == ' ') {
                shuttleclear(&term);
                shuttle.y -= 2;
            }
            break;
        case DOWN:

            if (map.map[shuttle.y + 3][shuttle.x] == ' ') {
                shuttleclear(&term);
                shuttle.y += 2;
            }
            break;
        case LEFT:
            if (map.map[shuttle.y][shuttle.x - 6] != '|' && score.speed == 1) {
                shuttleclear(&term);
                shuttle.x -= score.speed;
            }
            if (map.map[shuttle.y][shuttle.x - 7] != '|' && score.speed == 2) {
                shuttleclear(&term);
                shuttle.x -= score.speed;
            }
            if (map.map[shuttle.y][shuttle.x - 8] != '|' && score.speed == 3){
                shuttleclear(&term);
                shuttle.x -= score.speed;
            }
            break;
        case RIGHT:
            if (map.map[shuttle.y][shuttle.x + 4] != '|' && score.speed == 1) {
                shuttleclear(&term);
                shuttle.x += score.speed;
            }
            if (map.map[shuttle.y][shuttle.x + 6] != '|' && score.speed == 2){
                shuttleclear(&term);
                shuttle.x += score.speed;
            }
            if (map.map[shuttle.y][shuttle.x + 7] != '|' && score.speed == 3){
                shuttleclear(&term);
                shuttle.x += score.speed;
            }
            break;
        case ' ':
            if (map.map[shuttle.y - 2][shuttle.x] == ' '){
                shots.flag = false;
            }
        }
    }
    endwin();
    return 0;
}
