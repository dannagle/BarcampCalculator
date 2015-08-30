#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_calcButton_clicked();

    void on_clearButton_clicked();

    void on_calcEdit_returnPressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
