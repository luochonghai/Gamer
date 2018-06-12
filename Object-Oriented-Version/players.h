#pragma once
#include"stdafx.h"
#include<string>

using namespace std;

class Player
{
public:
	Player();
	string get_name();
	void set_name(string name_);
	void update_score();
	void update_history(int res);
	int* read_hostory();
	void make_choice(int choice);
	int get_score();

private:
	/*name: */
	string name;
	int score;
	int history[MW_LEN+1];//remember 8 records:new->old(left->right)
};