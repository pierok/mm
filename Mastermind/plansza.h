#ifndef PLANSZA_H
#define PLANSZA_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "selectframe.h"


class Plansza: public QGraphicsScene
{
public:
    Plansza();
    void update();
    SelectFrame *frame;
    bool checkPatern();

    void clearP();

    int patern[8];
    int result[8];

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PLANSZA_H
