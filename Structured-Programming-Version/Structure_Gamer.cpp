// Structure_Gamer.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "func.h"

using namespace std;

int main()
{
	string player_name;
	string robot_name[RB_LEN];
	int player_score = 0;
	int robot_score[RB_LEN] = { 0 };
	int player_history[MW_LEN + 1] = { 0 };
	int robot_history[RB_LEN][MW_LEN + 1] = { 0 };
	int robot_weight[RB_LEN][ST_NUM] = { 0 };
	int robot_strategy[RB_LEN][ST_NUM][ST_SIZE];
	int bar_num, home_num;
	int pc_life = 1;
	string player_choice;
	cout << "Welcome to this game!\nPlease input your name(no more than 6 char):";
	while (cin >> player_name) {
		if (player_name.length() < 1 || player_name.length() > 6) {
			cout << "re input your name:";
		}
		else
			break;
	}
	initialize_robots(robot_name, robot_strategy);
	while (pc_life <= LIFE_CYCLE) {
		cout << "---------Round " << pc_life++ << "--------" << endl;
		reset(bar_num, home_num);
		bool bar_win;
		cout << "Please choose as follows with a number:\n1.Go bar\t2.Stay home\t3.Show status(●-win  ○-lose)" << endl;
		while (cin >> player_choice) {
			if (player_choice.length() != 1) {
				cout << "Error number" << endl;
				cout << "Please choose as follows with a number:\n1.Go bar\t2.Stay home\t3.Show status" << endl;
				continue;
			}
			char choice = player_choice[0];
			switch (choice) {
			case '1':
				bar_num++;
				player_make_choice(1, player_history);
				robot_choose(robot_history, robot_strategy, robot_weight, bar_num, home_num);
				bar_win = bar_num < home_num;
				if (bar_win) {
					update_history(0, player_history);
					update_score(player_history[0], player_score);
					for (int i = 0; i < RB_LEN; i++) {
						update_weight(i, 1, robot_weight[i], robot_strategy[i], robot_history[i]);
						update_history(0, robot_history[i]);
						update_score(robot_history[i][0], robot_score[i]);
					}
					cout << "★★★★★恭喜您当局获胜★★★★★" << endl;
				}
				else {
					update_history(1, player_history);
					update_score(player_history[0], player_score);
					for (int i = 0; i < RB_LEN; i++) {
						update_weight(i, 0, robot_weight[i], robot_strategy[i], robot_history[i]);
						update_history(1, robot_history[i]);
						update_score(robot_history[i][0], robot_score[i]);
					}
					cout << "XXXXX遗憾您在当局失败XXXXX" << endl;
				}
				break;
			case '2':
				home_num++;
				player_make_choice(0, player_history);
				robot_choose(robot_history, robot_strategy, robot_weight, bar_num, home_num);
				bar_win = bar_num < home_num;
				if (bar_win) {
					update_history(0, player_history);
					update_score(player_history[0], player_score);
					for (int i = 0; i < RB_LEN; i++) {
						update_weight(i, 1, robot_weight[i], robot_strategy[i], robot_history[i]);
						update_history(0, robot_history[i]);
						update_score(robot_history[i][0], robot_score[i]);
					}
					cout << "XXXXX遗憾您在当局失败XXXXX" << endl;
				}
				else {
					update_history(1, player_history);
					update_score(player_history[0], player_score);
					for (int i = 0; i < RB_LEN; i++) {
						update_weight(i, 0, robot_weight[i], robot_strategy[i], robot_history[i]);
						update_history(1, robot_history[i]);
						update_score(robot_history[i][0], robot_score[i]);
					}
					cout << "★★★★★恭喜您当局获胜★★★★★" << endl;
				}
				break;
			case '3':
				cout << "-----------------------" << endl;
				cout << "history:\t1\t2\t3\t4\t5\t6\t7\t8" << endl;
				cout << player_name << "\t\t";
				for (int i = 0; i < MW_LEN; i++) {
					if (player_history[i] == 1)
						cout << "●\t";
					else
						cout << "○\t";
				}
				cout << endl;
				for (int i = 0; i < RB_LEN; i++) {
					cout << robot_name[i] << "\t\t";
					for (int j = 0; j < MW_LEN; j++) {
						if (robot_history[i][j] == 1)
							cout << "●\t";
						else
							cout << "○\t";
					}
					cout << endl;
				}
				cout << "-----------------------" << endl;
				cout << "Please choose as follows with a number:\n1.Go bar\t2.Stay home\t3.Show status" << endl;
				continue;
			default:
				cout << "Error number" << endl;
				cout << "Please choose as follows with a number:\n1.Go bar\t2.Stay home\t3.Show status" << endl;
				continue;
			}
			break;
		}
	}
	cout << "您的总得分是：" << player_score << endl;
	cout << "游戏结束" << endl;
    return 0;
}

