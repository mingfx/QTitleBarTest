#pragma once

#include <QtWidgets/QWidget>
#include "ui_BaseWindow.h"

class BaseWindow : public QWidget
{
	Q_OBJECT

public:
	BaseWindow(QWidget *parent = Q_NULLPTR);
	~BaseWindow();

private:
	void InitTitleBar();
	void PaintEvent(QPaintEvent *event);
	void LoadStyleSheet(const QString &sheetName);
	Ui::BaseWindowClass ui;
private slots:
void on_ButtonMin_clicked();
void on_ButtonRestore_clicked();
void on_ButtonMax_clicked();
void on_ButtonClose_clicked();
};
