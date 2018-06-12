// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<Python.h>

#define ST_NUM 5//number of strategies
#define MW_LEN 8//the lifecycle of history table
#define RB_LEN 8//the numbers of robot
#define ST_SIZE 2<<MW_LEN//numbers of entries in each stategy table
#define LIFE_CYCLE 100 //number of turns to play the game

void ten2two(int*, int, int);
int two2ten(int*);
