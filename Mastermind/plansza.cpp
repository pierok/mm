#include "plansza.h"
#include<iostream>
Plansza::Plansza()
{

    frame= new  SelectFrame();
    for(int i=0; i<8; ++i)
    {
        addItem(frame->memory[i]);
        patern[i]=i+1;
        result[i]=0;
    }
    addItem(frame);
}


void Plansza::clearP()
{

    std::cout<<"aaaa "<<items().size()<<std::endl;
    foreach(QGraphicsItem *item, items())
    {
        //SelectFrame *object = dynamic_cast<SelectFrame*> (item);
        StaticElipse *object = dynamic_cast<StaticElipse*> (item);

        if(object!=NULL)
        {
            removeItem(object);
        }
    }

       std::cout<<"bbb "<<items().size()<<std::endl;
}

void Plansza::update()
{
    foreach(QGraphicsItem *item, items())
    {
        item->update();
    }
}


bool Plansza::checkPatern()
{

    int tmp[8];

    for(int i=0; i<8; ++i)
    {
        result[i]=0;
        tmp[i]=0;
    }

    for(int i=0; i<8; ++i)
    {

        if(patern[i]==frame->memory[i]->getColor())
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
            if(patern[j]==frame->memory[i]->getColor())
            {
                if(tmp[j]==1)
                    pos=false;
                tmp[j]=1;

            }
        }

        if(pos&&frame->memory[i]->getColor()>0)
        {
            result[i]=2;
           // tmp[i]=1;
        }

    }

    for(int i=0; i<8; ++i)
    {
        if(result[i]==0||result[i]==2)
        {
            return false;
        }
    }

    return true;

}


void Plansza::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    frame->frameClicked(event->scenePos().x(),event->scenePos().y());
    update();
    event->accept();
}

