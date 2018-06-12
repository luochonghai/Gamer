#pragma once

#include "stdafx.h"
#include <QtWidgets/QMainWindow>
#include "ui_SE.h"
#include <qstandarditemmodel.h>

#include "players.h"
#include "Robot.h"
#include "Controller.h"
#include "pychart.h"

using namespace std;


class SE : public QMainWindow
{
	Q_OBJECT

public:
	SE(QWidget *parent = Q_NULLPTR);

public slots:
	void goBarButtonFuc();
	void changeStatus();
	void setnameButtonFuc();
	void continueButtonFuc();
	void stayHomeButtonFuc();

private:
	Ui::SEClass ui;
	QStandardItemModel *model;
	Player *player;
	Robot** computer;
	Controller *controller;
	int pc_life = 0;
	void robotsChoose();
};
