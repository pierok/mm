#include <iostream>
#include <cmath>
#include <QMessageBox>
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
    plansza->setSceneRect(0, 0,400, 400);
    plansza->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->plansza->setScene(plansza);
    ui->plansza->show();

    maintimer.start(30);
    start=false;

    populacja= new Populacja(400);
    algorytm= new AlgorytmGenetyczny(populacja);

}

void MainWindow::MainClockTick()
{
    if(start==true)
    {
        int os=qrand()%populacja->getRozmiar();
       // std::cout<<"Osobnik: "<<os<<std::endl;
        osobnik=algorytm->osobnik(os);

        for(int i=0; i<8; ++i)
        {
            plansza->frame->memory[i]->setColor(osobnik->genom[i]);
        }

        /*std::cout<<"Osobnik :";
        for(int i=0; i<8; ++i)
        {
            std::cout<< plansza->frame->memory[i]->getColor()<<" ";
        }std::cout<<std::endl;*/

        on_acceptButton_clicked();

        oceneOsobnikow(osobnik,os);

        algorytm->update();

        if(algorytm->pokolenie>6)
        {
            start=false;
            algorytm->pokolenie=0;
        }
    }
    plansza->update();
}

void MainWindow::oceneOsobnikow(Osobnik *osobnik, int os)
{
    int count1=0;
    int count2=0;

    for(int i=0; i<8; ++i)
    {
        if(plansza->result[i]==1)
        {
            ++count1;
        }else if(plansza->result[i]==2)
        {
            ++count2;
        }
    }

    Memento* m=new Memento();
    m->setBlack(count1);
    m->setWhite(count2);
    for(int i=0; i<8; ++i)
    {
        m->setResult(i,plansza->result[i]);
        m->setPresented(i,osobnik->genom[i]);
    }


    osobnik->przystosowanie=count1-count2-8;

    previousResults.push_back(m);

    int tmp[8];
    int result[8];

    foreach(Memento* m, previousResults)
    {
        foreach(Osobnik* o, *populacja->populacja)
        {


            for(int i=0; i<8; ++i)
            {
                result[i]=0;
                tmp[i]=0;
            }

            for(int i=0; i<8; ++i)
            {

                if(m->getPresented(i)==o->genom[i])
                {
                    result[i]=1;
                    tmp[i]=1;
                }
            }

            for(int i=0; i<8; ++i)
            {
                bool pos=true;
                for(int j=0; j<8; ++j)
                {
                    if(m->getPresented(j)==o->genom[i])
                    {
                        if(tmp[j]==1)
                            pos=false;
                        tmp[j]=1;

                    }
                }

                if(pos&&o->genom[i]>0)
                {
                    result[i]=2;
                   // tmp[i]=1;
                }

            }

            int black=0;
            int white=0;
            for(int i=0; i<8; ++i)
            {
                if(result[i]==1)
                {
                    ++black;
                }else if(result[i]==2)
                {
                    ++white;
                }
            }
           // std::cout<<k<<" "<<"M b: "<<m->getBlack()<<" b: "<<black<<" M w: "<<m->getWhite()<<" w :"<<white<<std::endl;

        }

    }
    std::cout<<"ok "<<previousResults.size()<<" "<<populacja->getRozmiar()<<std::endl;


  //  std::cout<<"przystosowanie: "<<osobnik->przystosowanie<<" 1: "<<count1<<" 2: "<<count2<<std::endl;
}





MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_acceptButton_clicked()
{
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
        QString code;
        std::cout<<"Kod: ";
        for(int i=0; i<8; ++i)
        {
            std::cout<<plansza->result[i]<<" ";
            code.setNum(plansza->frame->memory[i]->getColor());
        }
        std::cout<<std::endl;
        QMessageBox msgBox;
        msgBox.setText(code);
        msgBox.setFixedSize(300,300);
        msgBox.exec();
    }

    for(int i=0; i<8; ++i)
    {
        // std::cout<<plansza->result[i]<<" ";
    }
    plansza->frame->clearMemory();
    plansza->frame->level++;

    plansza->update();
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
