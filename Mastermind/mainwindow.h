#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "plansza.h"
#include "populacja.h"
#include "algorytmgenetyczny.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer maintimer;
    Plansza *plansza;
    AlgorytmGenetyczny *algorytm;
    Osobnik* osobnik;
    bool start;

private slots:
    void MainClockTick();
    void on_acceptButton_clicked();
    void on_newGameButton_clicked();
};

#endif // MAINWINDOW_H
