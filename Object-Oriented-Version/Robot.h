#pragma once
#include"stdafx.h"
using namespace std;

class Robot
{
public:
	Robot();
	Robot(string name_);
	vector<int> select_max();
	string get_name();
	int get_score();
	int select_by_max(vector<int> s);
	int* read_history();
	void update_history(int res);
	void update_score();
	void update_weight(int res);
	void make_choice(int choice);
	int make_choice_by_strategy(int strategy_num);
	void update(int);

private:
	string name;
	int history[MW_LEN+1];
	int weight[ST_NUM];//5 strategy (tables)
	int strategy[ST_NUM][ST_SIZE];
	int score;
};
