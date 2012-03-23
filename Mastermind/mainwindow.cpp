#include <iostream>
#include <cmath>
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    connect(&maintimer, SIGNAL(timeout()), this, SLOT(MainClockTick()));

    plansza = new Plansza();
    plansza->setSceneRect(0, 0, 400, 400);
    plansza->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->plansza->setScene(plansza);
    ui->plansza->show();
    maintimer.start(30);
    start=false;

    Populacja* p= new Populacja(1000);
    algorytm= new AlgorytmGenetyczny(p);

}

void MainWindow::MainClockTick()
{
    if(start==true)
    {
        algorytm->update();
        osobnik=algorytm->osobnik();
        for(int i=0; i<8; ++i)
        {
            plansza->frame->memory[i]->setColor(osobnik->genom[i]);
        }

        std::cout<<"Osobnik :";
        for(int i=0; i<8; ++i)
        {
            std::cout<< plansza->frame->memory[i]->getColor()<<" ";
        }std::cout<<std::endl;


        on_acceptButton_clicked();



    }
    plansza->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_acceptButton_clicked()
{
   // if(plansza->frame->scenePos().y()<400)
   // {
        plansza->frame->setPos(plansza->frame->scenePos().x(),plansza->frame->scenePos().y()+55);

        for(int i=0; i<8; ++i)
        {
            StaticElipse *tmp=new StaticElipse(0,0,i);
            tmp->setColor(plansza->frame->memory[i]->getColor());

            plansza->addItem(tmp);
            tmp->setPos(plansza->frame->memory[i]->scenePos().x(),plansza->frame->memory[i]->scenePos().y());

            plansza->frame->memory[i]->setPos(plansza->frame->memory[i]->scenePos().x(),plansza->frame->memory[i]->scenePos().y()+55);
        }

        if(plansza->checkPatern())
        {
            start=false;
            std::cout<<"Kod: ";
            for(int i=0; i<8; ++i)
            {
               std::cout<<plansza->result[i]<<" ";
            }
            std::cout<<std::endl;
        }

        for(int i=0; i<8; ++i)
        {
         //   std::cout<<plansza->result[i]<<" ";
        }

        std::cout<<std::endl;


        plansza->frame->clearMemory();
        plansza->frame->level++;

        plansza->update();

    //}

}

void MainWindow::on_newGameButton_clicked()
{

    start=true;
    plansza->frame->setPos(0.,0.);
    for(int i=0; i<8; ++i)
    {
        plansza->frame->memory[i]->setPos(plansza->frame->memory[i]->scenePos().x(),0);
    }
    plansza->frame->level=0;
    plansza->frame->clearMemory();
    plansza->clearP();

    this->repaint();
    ui->plansza->repaint();
}
