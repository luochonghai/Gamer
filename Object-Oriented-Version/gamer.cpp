#include"stdafx.h"
#include"Robot.h"
#include"players.h"
#include"Controller.h"
using namespace std;

//int main()
//{
//	//to initialize the GUI & Player,Robots,Controller
//	/*initialize GUI*/
//
//	/*initialize others*/
//	Player zjman(0);
//	Robot* computer = new Robot[MW_LEN];
//	for (int i = 0; i < MW_LEN; ++i)
//	{
//		computer[i] = Robot(to_string(i));
//	}
//	Controller controller;
//
//	//to get the name of Player
//	string zj_name;
//	cin >> zj_name;
//
//	//to start the game:loop
//	int pc_life = LIFE_CYCLE;
//	while (pc_life--)
//	{
//		/*step0:play or read_history
//		step0.1--get signal
//		branch:
//			step0.2.0->show history_table
//			step0.2.1->go on*/
//
//
//		/*step1.0:transfer signal to data
//		step1.1:Robot make choices*/
//
//		/*step2:calculate the result*/
//
//		/*step3:update Player&Robot history,weight*/
//	}
//	return 0;
//}