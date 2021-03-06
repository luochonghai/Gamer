#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <Windows.h>
//#include<Python.h>

#define ST_NUM 5//number of strategies
#define MW_LEN 8//the lifecycle of history table
#define RB_LEN 8//the numbers of robot
#define ST_SIZE 2<<MW_LEN//numbers of entries in each stategy table
#define LIFE_CYCLE 100 //number of turns to play the game

void ten2two(int*, int, int);
int two2ten(int*);
