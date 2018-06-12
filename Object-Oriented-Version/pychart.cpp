#include"pychart.h"
using namespace std;

void headcount_chart(Controller* controller, Player* players,Robot** rob)
{
	//1.write data to headcount.txt
	system("DEL /f D:\\FDU\\Template\\CS\\software_engineering\\pj\\headcount.txt");
	ofstream headtxt;
	headtxt.open("D:\\FDU\\Template\\CS\\software_engineering\\pj\\headcount.txt", ios::out | ios::app);
	auto charts = controller->get_chart();
	for (int i = 0; i < MW_LEN; ++i)
		headtxt << charts[i] << " ";
	headtxt.close();

	//2.write data to capital.txt
	system("DEL /f D:\\FDU\\Template\\CS\\software_engineering\\pj\\capital.txt");
	ofstream capi_txt;
	capi_txt.open("D:\\FDU\\Template\\CS\\software_engineering\\pj\\capital.txt", ios::out | ios::app);
	//player data
	int player_cap = players->get_score();
	auto player_history = players->read_hostory();
	for (int i = 0; i < MW_LEN; ++i)
	{
		capi_txt << player_cap - player_history[i] << " ";
		player_cap -= player_history[i];
	}
	capi_txt << endl;

	for (int i = 0; i < MW_LEN; ++i)//robot index loop
	{
		int robot_cap = rob[i]->get_score();
		auto robot_history = rob[i]->read_history();
		for (int j = 0; j < MW_LEN; ++j)//round loop
		{
			capi_txt << robot_cap - robot_history[j] << " ";
			robot_cap -= robot_history[j];
		}
		capi_txt << endl;
	}
	capi_txt.close();

	//3.call .py
	PyObject *pModule = NULL;
	PyObject *pFunc = NULL;
	PyRun_SimpleString("import sys;sys.path.append('./')");
	PyObject* moduleName = PyUnicode_FromString("pychart");
	pModule = PyImport_Import(moduleName);

	//define the invoking function's name
	pFunc = PyObject_GetAttrString(pModule, "like_main");
	PyEval_CallObject(pFunc, NULL);

	//finish the invoking process

}