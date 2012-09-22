#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "plansza.h"
#include "populacja.h"
#include "algorytmgenetyczny.h"
#include "memento.h"

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
    int liczebnosc;

private:
    Ui::MainWindow *ui;
    QTimer maintimer;
    Plansza *plansza;
    Plansza* plansza2;
    Populacja* populacja;
    AlgorytmGenetyczny *algorytm;
    Osobnik* osobnik;
    bool start;
    QVector<Memento* >previousResults;

private slots:
    void MainClockTick();
    void on_acceptButton_clicked();
    void on_newGameButton_clicked();
    void on_wzorButton_clicked();
};

#endif // MAINWINDOW_H
