#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    plansza = new Plansza();
    //plansza->setSceneRect(100, 0, 100, 400);
    //plansza->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->graphicsView->setScene(plansza);
    ui->graphicsView->show();

}


void Dialog::hideInfo()
{
    ui->label->hide();
    ui->label_2->hide();
    ui->labelLiczbaR->hide();
}

void Dialog::setInfo(int i)
{

    QString s="";
            s.setNum(i);
    ui->labelLiczbaR->setText(s);
}



Dialog::~Dialog()
{
    delete ui;
    delete plansza;
}

void Dialog::on_pushButton_clicked()
{
    this->done(10);
}
