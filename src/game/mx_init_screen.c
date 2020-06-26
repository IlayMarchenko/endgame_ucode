#include "game.h"

void mx_font_color(void);
void mx_background_color(void);

void mx_init_screen(WINDOW **term)
{
	*term = initscr(); /* Initialize terminal */

	start_color(); /* Initialize colors */

	mx_font_color();
	mx_background_color();

	cbreak();
	noecho();
	nodelay(*term,TRUE); /* Don't block while waiting for input */

	curs_set(0);
	nonl();
	intrflush(*term,FALSE);
	keypad(*term,TRUE);

	wrefresh(*term);
}

void mx_font_color(void) {
	init_pair(PC_WHITE, COLOR_WHITE, COLOR_BLACK);
	init_pair(PC_RED, COLOR_RED, COLOR_BLACK);
	init_pair(PC_GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(PC_YELLOW, COLOR_YELLOW, COLOR_BLACK);
	init_pair(PC_BLUE, COLOR_BLUE, COLOR_BLACK);
	init_pair(PC_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(PC_CYAN, COLOR_CYAN, COLOR_BLACK);
}

void mx_background_color(void) {
	init_color(BG_WHITE, 200, 200, 200);
	init_pair(BG_WHITE, COLOR_WHITE, BG_WHITE);

	init_color(BG_RED, 800, 0, 0);
	init_pair(BG_RED, BG_RED, BG_WHITE);

	init_color(BG_BLUE, 0, 0, 500);
	init_pair(BG_BLUE, BG_BLUE, BG_WHITE);

	init_color(BG_YELLOW, 800, 800, 0);
	init_pair(BG_YELLOW, BG_YELLOW, BG_WHITE);

	init_color(BG_GREEN, 0, 800, 0);
	init_pair(BG_GREEN, BG_GREEN, BG_WHITE);

	init_pair(BGR_GREEN, BG_GREEN, BG_BLUE);
}
