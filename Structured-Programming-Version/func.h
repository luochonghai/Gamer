#pragma once
#include "stdafx.h"

using namespace std;

void initialize_robots(string[RB_LEN], int[RB_LEN][ST_NUM][ST_SIZE]);

void reset(int&, int&);

void player_make_choice(int, int[]);

void robot_choose(int[RB_LEN][MW_LEN + 1], int[RB_LEN][ST_NUM][ST_SIZE], int[RB_LEN][ST_NUM], int&, int&);

int make_choice(int, int[MW_LEN + 1], int[ST_NUM][ST_SIZE], int[ST_NUM]);

void update_history(int, int[]);

void update_score(int, int&);

void update_weight(int, int, int*, int[ST_NUM][ST_SIZE], int*);
