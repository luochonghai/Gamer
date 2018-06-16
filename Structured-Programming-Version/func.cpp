#include "stdafx.h"
#include "func.h"

void initialize_robots(string name[RB_LEN], int strategy[RB_LEN][ST_NUM][ST_SIZE]){
	int random_seed = 0;
	for (int i = 0; i < RB_LEN; i++) {
		srand((unsigned)time(NULL) + random_seed);
		name[i] = "Robot" + to_string(i + 1);
		for (int j = 0; j < ST_NUM; j++)
			for (int k = 0; k < ST_SIZE; k++)
				strategy[i][j][k] = rand() % 2;
		random_seed++;
	}
}

void reset(int& bar, int& home){
	bar = home = 0;
}

void player_make_choice(int choice, int history[]) {
	history[0] = choice;
}

void robot_choose(int history[RB_LEN][MW_LEN + 1], int stra[RB_LEN][ST_NUM][ST_SIZE], int weight[RB_LEN][ST_NUM], int& bar, int& home) {
	for (int i = 0; i < RB_LEN; i++) {
		int choice = make_choice(i, history[i], stra[i], weight[i]);
		if (choice)
			bar++;
		else
			home++;
	}
}

int make_choice(int i, int history[MW_LEN + 1], int strategy[ST_NUM][ST_SIZE], int weight[ST_NUM]) {
	vector<int>res;
	for (int i = 0, max_num = -1; i < ST_NUM; ++i)
	{
		if (max_num < weight[i])
		{
			res.clear();
			res.push_back(i);
			max_num = weight[i];
		}
		else if (max_num == weight[i])
		{
			res.push_back(i);
		}
	}
	srand((unsigned)time(NULL) + i);
	int choice = strategy[res[rand() % (res.size())]][two2ten(history + 1)];
	history[0] = choice;
	return choice;
}

void update_history(int res, int history[]) {
	history[0] = history[0] ^ res;
	for (int i = MW_LEN; i >0; i--) {
		history[i] = history[i - 1];
	}
}

void update_score(int res, int& score) {
	score += res;
}

void update_weight(int i, int res, int* weight, int strategy[ST_NUM][ST_SIZE], int* history) {
	for (int j = 0; j < ST_NUM; j++) {
		if (strategy[j][two2ten(history + 1)] == res)
			weight[j]++;
	}
}