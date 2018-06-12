#include"stdafx.h"
#include"Controller.h"

using namespace std;

Controller::Controller() :bar_num(0), home_num(0) 
{
	for (int i = 0; i < MW_LEN; ++i)
		chart[i] = 0;
}

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

void Controller::record_headcount()
{
	for (int i = MW_LEN - 2; i >= 0; --i)
		chart[i + 1] = chart[i];
	chart[0] = bar_num;
}

int* Controller::get_chart()
{
	return chart;
}