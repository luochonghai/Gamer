// stdafx.cpp : 只包括标准包含文件的源文件
// Structure_Gamer.pch 将作为预编译标头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用

int two2ten(int *inc)
{
	int temp = 1;
	int res = 0;
	for (int i = 0; i < MW_LEN; i++) {
		res += temp * inc[i];
		temp *= 2;
	}
	return res;
}
