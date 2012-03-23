#ifndef ELIPSEFRAME_H
#define ELIPSEFRAME_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

class ElipseFrame: public QGraphicsItem
{
public:
    ElipseFrame(){}
    ElipseFrame(int a, int b, int i);
    ~ElipseFrame(){nextElipse=NULL;}
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    QRectF  boundingRect() const;
    void    setBoundingRect(QRectF);

    void request(double x, double y);

    inline void setNextElipse(ElipseFrame *next)
    {
        nextElipse=next;
    }
    inline void setColor(int i)
    {
        color=i;
    }
    inline int getColor()
    {
        return color;
    }

protected:

    ElipseFrame *nextElipse;
    int x1,x2;
    int index;
    int color;
    QRectF m_boundingRect;
};

class StaticElipse: public ElipseFrame
{
public:
    StaticElipse(int a, int b, int c):ElipseFrame(a,b,c){}
};

#endif // ELIPSEFRAME_H
