<<<<<<< HEAD
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
    void oceneOsobnikow(Osobnik *osobnik, int os);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer maintimer;
    Plansza *plansza;
    Populacja* populacja;
    AlgorytmGenetyczny *algorytm;
    Osobnik* osobnik;
    bool start;

private slots:
    void MainClockTick();
    void on_acceptButton_clicked();
    void on_newGameButton_clicked();
};

#endif // MAINWINDOW_H
=======
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
>>>>>>> 71f1fe1a7f0e7da241082634dfd6908420743548
