#include "elipseframe.h"
#include <iostream>

ElipseFrame::ElipseFrame(int a, int b, int i):x1(a),x2(b),index(i)
{
    m_boundingRect=QRectF(25-10,25-10,40,40);
    color=0;
    nextElipse=NULL;
}

void ElipseFrame::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(QPen(Qt::black));

    if(color==0)
    {
        painter->setBrush(Qt::gray);
        painter->drawEllipse((25-5)+index*50,(25-5),10,10);
    }
    else if(color==1)
    {
        painter->setBrush(Qt::blue);
        painter->drawEllipse((25-15)+index*50,(25-15),30,30);
    }
    else if(color==2)
    {   painter->setBrush(Qt::red);
        painter->drawEllipse((25-15)+index*50,(25-15),30,30);
    }
    else if(color==3)
    {   painter->setBrush(Qt::green);
        painter->drawEllipse((25-15)+index*50,(25-15),30,30);
    }
    else if(color==4)
    {   painter->setBrush(Qt::white);
        painter->drawEllipse((25-15)+index*50,(25-15),30,30);
    }
    else if(color==5)
    {   painter->setBrush(Qt::cyan);
        painter->drawEllipse((25-15)+index*50,(25-15),30,30);
    }
    else if(color==6)
    {   painter->setBrush(Qt::darkRed);
        painter->drawEllipse((25-15)+index*50,(25-15),30,30);
    }
    else if(color==7)
    {   painter->setBrush(Qt::yellow);
        painter->drawEllipse((25-15)+index*50,(25-15),30,30);
    }
    else if(color==8)
    {   painter->setBrush(Qt::magenta);
        painter->drawEllipse((25-15)+index*50,(25-15),30,30);
    }
    else if(color==9)
    {   painter->setBrush(Qt::darkGray);
        painter->drawEllipse((25-15)+index*50,(25-15),30,30);
    }
}

void ElipseFrame::request(double x ,double y)
{
    if(x>x1 && x<x2 && y>0 && y<50)
    {
        color++;
        color=(color)%10;
    }else if(nextElipse!=NULL)
    {
        nextElipse->request(x,y);
    }
}

QRectF ElipseFrame::boundingRect() const
{
    return m_boundingRect;
}

void ElipseFrame::setBoundingRect(QRectF rect)
{
    m_boundingRect=rect;
}
