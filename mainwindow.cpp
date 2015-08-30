#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QString>
#include <QStringList>

#define DEBUG qDebug() << __FUNCTION__ << __LINE__


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Barcamp Calc");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calcButton_clicked()
{


    QString calcEntered = ui->calcEdit->text().simplified();
    QStringList calcList = calcEntered.split(" ");

    ui->calcEdit->setText(calcEntered);

    bool ok = false;

    if (calcList.size() == 3) {
        float num1, num2, result;
        QString num = calcList.at(0);
        num1 = num.toFloat(&ok);
        QString operand = calcList.at(1);
        num = calcList.at(2);
        num2 = num.toFloat(&ok);

        DEBUG << num1 << operand << num2;

        if(operand == "-") {
            result = num1 - num2;
        }
        if(operand == "+") {
            result = num1 + num2;
        }
        if(operand == "/") {
            result = num1 / num2;
        }
        if(operand == "*") {
            result = num1 * num2;
        }

        ui->resultsEdit->setText( QString::number(result) + "\n" + ui->resultsEdit->toPlainText());

    }

    DEBUG << "calc" << calcList;


}

void MainWindow::on_clearButton_clicked()
{
    DEBUG << "clear";

}

void MainWindow::on_calcEdit_returnPressed()
{
    on_calcButton_clicked();

}
