#include"stdafx.h"
#include"Controller.h"

using namespace std;

Controller::Controller() :bar_num(0), home_num(0) {}

bool Controller::calculate()
{
	return bar_num < home_num;
}

void Controller::reset()
{
	bar_num = home_num = 0;
}

void Controller::add_bar()
{
	bar_num++;
}

void Controller::add_home() 
{
	home_num++;
}
