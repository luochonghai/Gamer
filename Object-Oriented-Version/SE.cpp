#pragma execution_character_set("utf-8")
#include "SE.h"
#include <QMessageBox>

SE::SE(QWidget *parent)
	: QMainWindow(parent)
{
	player = new Player();
	computer = new Robot*[RB_LEN];
	for (int i = 0; i < RB_LEN; ++i)
		computer[i] = new Robot("robot" + to_string(i + 1));
	controller = new Controller();
	ui.setupUi(this);
	ui.tableView->hide();
	ui.verticalLayoutWidget->hide();
	ui.horizontalLayoutWidget->hide();
	ui.horizontalLayoutWidget_2->hide();
	ui.horizontalLayoutWidget_3->hide();
	ui.continueButton->hide();
	model = new QStandardItemModel();
	ui.tableView->setModel(model);
	model->setColumnCount(MW_LEN);
	model->setRowCount(1 + RB_LEN);
	for (int i = 0; i < MW_LEN; i++)
		model->setHeaderData(i, Qt::Horizontal, tr(to_string(i + 1).data()));
	ui.player_label->setText(tr(player->get_name().data()));
	QObjectList qol = ui.verticalLayoutWidget->children();
	qol.pop_front();
	for (int i = 1; i <= RB_LEN; i++)
		qobject_cast<QLabel*>(qol[i])->setText(tr(computer[i - 1]->get_name().data()));
}

void SE::goBarButtonFuc()
{
	controller->add_bar();
	player->make_choice(1);
	robotsChoose();
	if (controller->calculate()) {
		//newly added
		controller->record_headcount();

		player->update_history(0);
		player->update_score();
		for (int i = 0; i < RB_LEN; i++) {
			computer[i]->update_weight(1);
			computer[i]->update_history(0);
			computer[i]->update_score();
		}
		QMessageBox::about(this, tr("恭喜"), tr("您在本局去酒吧获胜"));
		ui.score_label->setNum(ui.score_label->text().toInt() + 1);
	}
	else {
		player->update_history(1);
		player->update_score();
		for (int i = 0; i < RB_LEN; i++) {
			computer[i]->update_weight(0);
			computer[i]->update_history(1);
			computer[i]->update_score();
		}
		QMessageBox::about(this, tr("遗憾"), tr("您在本局去酒吧失败"));
	}
	ui.round_label->setNum(ui.round_label->text().toInt() + 1);
	controller->reset();
	if (++pc_life == LIFE_CYCLE)
		if (QMessageBox::information(this, tr("游戏结束"), tr("game over")))
			qApp->quit();
}

void SE::stayHomeButtonFuc()
{
	controller->add_home();
	player->make_choice(0);
	robotsChoose();
	if (controller->calculate()) {
		//newly added
		controller->record_headcount();

		player->update_history(0);
		player->update_score();
		for (int i = 0; i < RB_LEN; i++) {
			computer[i]->update_weight(1);
			computer[i]->update_history(0);
			computer[i]->update_score();
		}
		QMessageBox::about(this, tr("遗憾"), tr("您在本局待在家失败"));
		ui.score_label->setNum(ui.score_label->text().toInt() + 1);
	}
	else {
		player->update_history(1);
		player->update_score();
		for (int i = 0; i < RB_LEN; i++) {
			computer[i]->update_weight(0);
			computer[i]->update_history(1);
			computer[i]->update_score();
		}
		QMessageBox::about(this, tr("恭喜"), tr("您在本局呆在家获胜"));
	}
	ui.round_label->setNum(ui.round_label->text().toInt() + 1);
	controller->reset();
	pc_life++;
	if (pc_life == LIFE_CYCLE)
		if (QMessageBox::information(this, tr("游戏结束"), tr("game over")))
			qApp->quit();
}

void SE::changeStatus()
{
	//newly added
	headcount_chart(controller,player,computer);

	for (int i = 0; i < MW_LEN; i++)
	{
		model->setItem(0, i, new QStandardItem(to_string(player->read_hostory()[i]).data()));
		model->item(0, i)->setTextAlignment(Qt::AlignCenter);
	}
	for (int i = 1; i <= RB_LEN; i++)
		for (int j = 0; j < MW_LEN; j++)
		{
			model->setItem(i, j, new QStandardItem(to_string(computer[i - 1]->read_history()[j]).data()));
			model->item(i, j)->setTextAlignment(Qt::AlignCenter);
		}
	ui.horizontalLayoutWidget->hide();
	ui.continueButton->show();
	ui.tableView->show();
	ui.verticalLayoutWidget->show();
}

void SE::setnameButtonFuc()
{
	string username = ui.name_text->text().toStdString();
	if (username == "")
	{
		QMessageBox::about(this, tr("警告"), tr("用户名不能为空"));
	}
	else {
		ui.player_label->setText(tr(username.data()));
		ui.name_text->close();
		ui.name_input_label->close();
		ui.name_button->close();
		ui.horizontalLayoutWidget->show();
		ui.horizontalLayoutWidget_2->show();
		ui.horizontalLayoutWidget_3->show();
	}
}

void SE::robotsChoose()
{
	for (int i = 0; i < RB_LEN; i++) {
		int choice = computer[i]->make_choice_by_strategy(computer[i]->select_by_max(computer[i]->select_max()));
		computer[i]->make_choice(choice);
		if (choice)
			controller->add_bar();
		else
			controller->add_home();
	}
}

void SE::continueButtonFuc()
{
	ui.tableView->hide();
	ui.verticalLayoutWidget->hide();
	ui.continueButton->hide();
	ui.horizontalLayoutWidget->show();
}
