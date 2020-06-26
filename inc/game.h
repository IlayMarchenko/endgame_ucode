#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
#include <sqlite3.h>
#include "defs.h"

struct enemy6 {
	int n1;
	int n;
	int count;
	bool flag;
	int x2;
	int y2;
} enem6;

struct enemy7 {
	int n1;
	int n;
	int count;
	bool flag;
	int x2;
	int y2;
} enem7;

struct enemy2 {
	int n1;
	int n;
	int count;
	bool flag;
	int x2;
	int y2;
} enem2;

struct life_score {
	int n1;
	int n;
	int count;
	bool flag;
	int x2;
	int y2;
} lifes ;

struct init_map {
	char map[53][90];
	int x;
	int y;
} map;

struct enemy3 {
	int n1;
	int n;
	int count;
	bool flag;
	int x2;
	int y2;
} enem3;

struct enemy4 {
	int n1;
	int n;
	int count;
	bool flag;
	int x2;
	int y2;
} enem4;

struct enemy5 {
	int n1;
	int n;
	int count;
	bool flag;
	int x2;
	int y2;
} enem5;

struct enemy1 {
	int n1;
	int n;
	int count;
	bool flag;
	int x2;
	int y2;
} enem1;

struct game_score {
	int lives;
	int scorenem;
	int lvl;
	int speed;
	int speedshot;
} score ;

struct shuttle_coor {
	int x;
	int y;
} shuttle;

struct shot_coord {
	int x;
	int y;
	bool flag;
	int count;
	int n;
	int n1;
} shots;

// void check_enemy(char **term);

void game_init(void);
void game_info(WINDOW **term);
void game_status(WINDOW **term);
void life(WINDOW **term);
void shot(WINDOW **term);
void enemy7(WINDOW **term);
void enemy6(WINDOW **term);
void enemy2(WINDOW **term);
void enemy4(WINDOW **term);
void enemy5(WINDOW **term);
void enemy3(WINDOW **term);
void init_map(void);
void shuttlef(WINDOW **term);
void shuttleclear(WINDOW **term);
void enemy(WINDOW **term);
void mx_startgame(WINDOW **term);
void mx_gameover(WINDOW **term);
void mx_displaymap(WINDOW **term);
void mx_init_screen(WINDOW **term);
void record(int result);

#endif
