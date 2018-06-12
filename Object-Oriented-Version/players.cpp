#include "stdafx.h"
#include"players.h"

using namespace std;

Player::Player()
{
	score = 0;
	for (int i = 0; i <= MW_LEN; i++)
		history[i] = 0;
}

string Player::get_name()
{
	return name;
}

void Player::set_name(string name_)
{
	name = name_;
}

void Player::update_score()
{
	score += history[0];
}

void Player::update_history(int res)
{	
	history[0] = history[0]^res;
	for (int i = MW_LEN-1; i >= 0;--i)
	{
		history[i + 1] = history[i];
	}
}

int* Player::read_hostory()
{
	return history + 1;
}

void Player::make_choice(int choice)
{
	history[0] = choice;
}

int Player::get_score()
{
	return score;
}