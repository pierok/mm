#ifndef SELECTFRAME_H
#define SELECTFRAME_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include "elipseframe.h"

class SelectFrame : public QGraphicsItem
{
public:

    SelectFrame();
    ~SelectFrame()
    {
        for(int i=0; i<8; ++i)
        {
            delete memory[i];
        }
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRectF  boundingRect() const;
    void    setBoundingRect(QRectF);

    ElipseFrame* memory[8];
    void clearMemory();
    void frameClicked(double x, double y);
    int level;

protected:

    QRectF m_boundingRect;

};

#endif // SELECTFRAME_H
