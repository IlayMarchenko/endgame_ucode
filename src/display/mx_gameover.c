#include "game.h"

void mx_delgameover(WINDOW **term,int gameOver_y,int gameOver_x);

static int callback(void *data, int argc, char **argv, char **azColName) {
    static int i = 0;
    (void)argc;
    WINDOW **win = (WINDOW**)data;
    int n = i + 1;
    mvwprintw(*win, 34 + i, 43, "%d.", n);
//    mvwprintw(*win, 33 + i, 43, ".");
    mvwprintw(*win, 34 + i, 46, argv[0]);
    azColName = NULL;
    i++;
    return 0;
}

static void error(int rc, char **err) {
    if (rc != SQLITE_OK) {
        sqlite3_free(*err);
        *err = NULL;
    }
}

void mx_gameover(WINDOW **term) {
	mx_displaymap(term);
	int gameOver_x = 12;
	int gameOver_y = 3;
    char *err_msg = NULL;
    sqlite3 *db;
    sqlite3_open("resource/records.db", &db);
    char *sql = "SELECT score FROM records;";
	char step = '\0';
	for (; gameOver_y <= 10; gameOver_y++){
		wattron(*term, COLOR_PAIR(BG_RED));
		mx_delgameover(term, gameOver_y,gameOver_x);
		mvwprintw(*term, gameOver_y, gameOver_x,     "  _________          _____             ___        ___       ______");
		mvwprintw(*term, gameOver_y + 1, gameOver_x, " /   ____ /         /     \\           /   \\      /   \\     |  ____|");
		mvwprintw(*term, gameOver_y + 2, gameOver_x, " |  |     ____     /  _    \\         /  /\\ \\    /  /\\ \\    | |____");
		mvwprintw(*term, gameOver_y + 3, gameOver_x, " |  |    |_   \\   /  / \\    \\       /  /  \\ \\  /  /  \\ \\   |  ____|");
		mvwprintw(*term, gameOver_y + 4, gameOver_x, " |  | _____|  |  /  /___\\    \\     /  /    \\ \\/  /    \\ \\  | |____");
		mvwprintw(*term, gameOver_y + 5, gameOver_x, " \\___________/  /_____________\\   /_ /      \\__ /      \\_\\ |______|");
	//-----------------------------------------------------------
		wattron(*term, COLOR_PAIR(BG_YELLOW));
		mvwprintw(*term, gameOver_y + 7, gameOver_x + 6,     " ________    _____     ___    _______    __________");
		mvwprintw(*term, gameOver_y + 8, gameOver_x + 6,     "/  ____  \\   \\    \\   /  /   |  _____|  |    ____  \\");
		mvwprintw(*term, gameOver_y + 9, gameOver_x + 6,     "| /    \\ |    \\    \\ /  /    | |_____   |   |____| /");
		mvwprintw(*term, gameOver_y + 10, gameOver_x + 6,     "| |    | |     \\    \\  /     |  _____|  |    ____  \\");
		mvwprintw(*term, gameOver_y + 11, gameOver_x + 6,     "| \\____/ |      \\    \\/      | |_____   |   |    \\  \\");
		mvwprintw(*term, gameOver_y + 12, gameOver_x + 6,     "\\________/       \\___/       |_______|  |___|     \\__\\");	
	//------------------------------------------------------------
		usleep(500000);
		step = getch();
      	if (step != ERR) {
        	while (getch() == step);
      	}
		wrefresh(*term);
	}
	wattron(*term, COLOR_PAIR(BG_WHITE));
	mvwprintw(*term, gameOver_y + 18, gameOver_x + 25, "Press Q to exit");
	mvwprintw(*term, gameOver_y + 19, gameOver_x + 25, "Your score - ");
	mvwprintw(*term, gameOver_y + 19, gameOver_x + 25 + 13, "%d", score.scorenem);
    mvwprintw(*term, gameOver_y + 21, gameOver_x + 25 + 5, "TOP  10");
    int rc = sqlite3_exec(db, sql, callback, term, &err_msg);
    error(rc, &err_msg);
	wattrset(*term, 0);
	wrefresh(*term);

	while (1) {
		step = getch();
		if (step == 'q') {
			break;
		}
		else if (step == 'Q') {
			break;
		}
	}
}

void mx_delgameover(WINDOW **term,int gameOver_y,int gameOver_x){
	mvwprintw(*term, gameOver_y - 1, gameOver_x,     "                                                                  ");
	mvwprintw(*term, gameOver_y + 1 - 1, gameOver_x, "                                                                   ");
	mvwprintw(*term, gameOver_y + 2 - 1, gameOver_x, "                                                                  ");
	mvwprintw(*term, gameOver_y + 3 - 1, gameOver_x, "                                                                   ");
	mvwprintw(*term, gameOver_y + 4 - 1, gameOver_x, "                                                                  ");
	mvwprintw(*term, gameOver_y + 5 - 1, gameOver_x, "                                                                   ");
	//-----------------------------------------------------------
	mvwprintw(*term, gameOver_y + 7 - 1, gameOver_x + 6,     "                                                   ");
	mvwprintw(*term, gameOver_y + 8 - 1, gameOver_x + 6,     "                                                    ");
	mvwprintw(*term, gameOver_y + 9 - 1, gameOver_x + 6,     "                                                    ");
	mvwprintw(*term, gameOver_y + 10 - 1, gameOver_x + 6,    "                                                    ");
	mvwprintw(*term, gameOver_y + 11 - 1, gameOver_x + 6,    "                                                     ");
	mvwprintw(*term, gameOver_y + 12 - 1, gameOver_x + 6,    "                                                      ");	
	//------------------------------------------------------------
	mvwprintw(*term, gameOver_y + 18 - 1, gameOver_x + 25, "                   ");
	mvwprintw(*term, gameOver_y + 19 - 1, gameOver_x + 25, "                ");
}

