#include"stdafx.h"
#include"Robot.h"
using namespace std;

int random_seed = 1;

Robot::Robot() = default;

Robot::Robot(string name_):
	name(name_)
{
	score = 0;
	for (int i = 0; i <= MW_LEN; i++)
		history[i] = 0;
	for (int i = 0; i < ST_NUM; ++i)
		weight[i] = 0;

	//to randomly initialize strategy
	srand(random_seed);
	random_seed++;
	for (int i = 0; i < ST_NUM; ++i)
	{
		for (int j = 0; j < ST_SIZE; ++j)
			strategy[i][j] = rand() % 2;
	}
}

vector<int> Robot::select_max()
{
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
	return res;
}

string Robot::get_name()
{
	return name;
}

int Robot::select_by_max(vector<int> s)
{
	srand(random_seed);
	random_seed++;
	return s[rand()%(s.size())];
}

int* Robot::read_history()
{
	return history + 1;
}

void Robot::update_history(int res)
{	
	history[0] = history[0]^res;
	for (int i = MW_LEN - 1; i >= 0; --i)
	{
		history[i + 1] = history[i];
	}
}

void Robot::update_score()
{
	score += history[0];
}

void Robot::update_weight(int res)
{
	for (int i = 0; i < ST_NUM; i++)
		if (strategy[i][two2ten(history + 1)] == res)
			weight[i]++;
}

void Robot::make_choice(int choice)
{
	history[0] = choice;
}

int Robot::make_choice_by_strategy(int strategy_num)
{
	return strategy[strategy_num][two2ten(history + 1)];
}

int Robot::get_score()
{
	return score;
}