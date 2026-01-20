#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Calculator.h"

class Calculator : public QMainWindow
{
	Q_OBJECT

public:
	Calculator(QWidget* parent = nullptr);
	~Calculator();

private:
	Ui::CalculatorClass ui;
};

