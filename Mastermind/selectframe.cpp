<<<<<<< HEAD
#include "selectframe.h"
#include <iostream>
SelectFrame::SelectFrame()
{
    m_boundingRect=QRectF(0,0,400,50);
    level=0;
    memory[0]=new ElipseFrame(0,50,0);
    memory[1]=new ElipseFrame(50,100,1);
    memory[2]=new ElipseFrame(100,150,2);
    memory[3]=new ElipseFrame(150,200,3);
    memory[4]=new ElipseFrame(200,250,4);
    memory[5]=new ElipseFrame(250,300,5);
    memory[6]=new ElipseFrame(300,350,6);
    memory[7]=new ElipseFrame(350,400,7);

    memory[0]->setNextElipse(memory[1]);
    memory[1]->setNextElipse(memory[2]);
    memory[2]->setNextElipse(memory[3]);
    memory[3]->setNextElipse(memory[4]);
    memory[4]->setNextElipse(memory[5]);
    memory[5]->setNextElipse(memory[6]);
    memory[6]->setNextElipse(memory[7]);
}

void SelectFrame::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //painter->setBrush(Qt::gray);
    painter->setPen(QPen(Qt::black,2));
    painter->drawRect(0, 0, 400, 50);
    painter->drawLine(50,0,50,50);
    painter->drawLine(100,0,100,50);
    painter->drawLine(150,0,150,50);
    painter->drawLine(200,0,200,50);
    painter->drawLine(250,0,250,50);
    painter->drawLine(300,0,300,50);
    painter->drawLine(350,0,350,50);
}

void SelectFrame::clearMemory()
{
    for(int i=0; i<8;++i)
    {
        memory[i]->setColor(0);
    }
}

void SelectFrame::frameClicked(double x, double y)
{
    memory[0]->request(x,y-level*55);
}

QRectF SelectFrame::boundingRect() const
{
    return m_boundingRect;
}

void SelectFrame::setBoundingRect(QRectF rect)
{
    m_boundingRect=rect;
}
=======
#include "selectframe.h"
#include <iostream>
SelectFrame::SelectFrame()
{
    m_boundingRect=QRectF(0,0,400,50);
    level=0;
    memory[0]=new ElipseFrame(0,50,0);
    memory[1]=new ElipseFrame(50,100,1);
    memory[2]=new ElipseFrame(100,150,2);
    memory[3]=new ElipseFrame(150,200,3);
    memory[4]=new ElipseFrame(200,250,4);
    memory[5]=new ElipseFrame(250,300,5);
    memory[6]=new ElipseFrame(300,350,6);
    memory[7]=new ElipseFrame(350,400,7);

    memory[0]->setNextElipse(memory[1]);
    memory[1]->setNextElipse(memory[2]);
    memory[2]->setNextElipse(memory[3]);
    memory[3]->setNextElipse(memory[4]);
    memory[4]->setNextElipse(memory[5]);
    memory[5]->setNextElipse(memory[6]);
    memory[6]->setNextElipse(memory[7]);
}

void SelectFrame::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    //painter->setBrush(Qt::gray);
    painter->setPen(QPen(Qt::black,2));

    painter->drawRect(0, 0, 400, 50);

    painter->drawLine(50,0,50,50);
    painter->drawLine(100,0,100,50);
    painter->drawLine(150,0,150,50);
    painter->drawLine(200,0,200,50);
    painter->drawLine(250,0,250,50);
    painter->drawLine(300,0,300,50);
    painter->drawLine(350,0,350,50);


}

void SelectFrame::clearMemory()
{
    for(int i=0; i<8;++i)
    {
        memory[i]->setColor(0);
    }
}


void SelectFrame::frameClicked(double x, double y)
{
    memory[0]->request(x,y-level*55);
}


QRectF SelectFrame::boundingRect() const
{
    return m_boundingRect;
}

void SelectFrame::setBoundingRect(QRectF rect)
{
    m_boundingRect=rect;
}

>>>>>>> 71f1fe1a7f0e7da241082634dfd6908420743548
