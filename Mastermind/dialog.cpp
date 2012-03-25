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

Dialog::~Dialog()
{
    delete ui;
}
