#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "plansza.h"

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    Plansza *plansza;

    ~Dialog();

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
