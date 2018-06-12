#pragma once
#include"stdafx.h"
using namespace std;

class Controller
{
public:
	Controller();
	bool calculate();//1:Bar win ; 0:Home win
	void reset();
	void add_bar();
	void add_home();
	void record_headcount();
	int* get_chart();

private:
	int bar_num;
	int home_num;
	int chart[MW_LEN];
};