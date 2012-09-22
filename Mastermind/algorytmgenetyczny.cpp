#include "algorytmgenetyczny.h"
//#include <algorithm>
#include <qalgorithms.h>
#include <QFile>
#include <QTextStream>
AlgorytmGenetyczny::AlgorytmGenetyczny(Populacja *pop)
{
    populacja=pop;
    pokolenie=0;
}

Osobnik* AlgorytmGenetyczny::osobnik(int os)
{
    //std::cout<<"osobnik: "<<o<<std::endl;
    return populacja->populacja->at(os);
}

void AlgorytmGenetyczny::mutacja()
{
    //std::cout<<"Mutacja "<<std::endl;
    for(int i=0; i<populacja->getRozmiar();++i)
    {
        int m=qrand()%100+1;

        if(m<=40)
        {
            int pos=qrand()%8;
            if(populacja->populacja->at(i)->genom[pos]>0 && populacja->populacja->at(i)->genom[pos]<9)
            {
                populacja->populacja->at(i)->genom[pos]+=1;
            }
            else
            {
                populacja->populacja->at(i)->genom[pos]=1;
            }
        }
    }
}

void AlgorytmGenetyczny::krzyzowanie()
{
    // std::cout<<"Krzyzowanie "<<std::endl;
    int rozmiar=populacja->getRozmiar();
    int nextCh=rozmiar/2;
    int nextCh2=rozmiar/2+1;

    while(nextCh2<rozmiar)
    {
        int p1=qrand()%rozmiar/2;
        int p2=qrand()%rozmiar/2;

        int m=qrand()%100+1;

        if(m<=40)
        {

            int pos=qrand()%8;

            Osobnik* o1=populacja->populacja->at(p1);
            Osobnik* o2=populacja->populacja->at(p2);

            for(int j=0; j<pos; ++j)
            {
                populacja->populacja->at(nextCh)->genom[j]=o1->genom[j];
                populacja->populacja->at(nextCh2)->genom[j]=o2->genom[j];
            }

            for(int j=pos; j<8; ++j)
            {
                populacja->populacja->at(nextCh)->genom[j]=o2->genom[j];
                populacja->populacja->at(nextCh2)->genom[j]=o1->genom[j];
            }
            nextCh+=2;
            nextCh2+=2;
        }
    }

}


void AlgorytmGenetyczny::transpozycja()
{
    foreach(Osobnik* o, *populacja->populacja)
    {
        int m=qrand()%100+1;

        if(m<=40)
        {
            int ilosZmian=qrand()%8;

            for(int i=0; i<ilosZmian; ++i)
            {
                int p1=qrand()%8;
                int p2=qrand()%8;

                int tmp=o->genom[p1];
                o->genom[p1]=o->genom[p2];
                o->genom[p2]=tmp;
            }
        }

    }

}

void AlgorytmGenetyczny::nowaPopulcacja()
{

    // std::cout<<"pokolenie "<<pokolenie<<std::endl;
          foreach(Osobnik* o, *populacja->populacja)
        {
            int g1=qrand()%8+1;
            int g2=qrand()%8+1;
            int g3=qrand()%8+1;
            int g4=qrand()%8+1;
            int g5=qrand()%8+1;
            int g6=qrand()%8+1;
            int g7=qrand()%8+1;
            int g8=qrand()%8+1;

            o->newGenoem(g1,g2,g3,g4,g5,g6,g7,g8);
        }

        std::cout<<"stwurz nowa populacje"<<std::endl;
       // pokolenie=0;
}


bool osobnikSelect(Osobnik* o1, Osobnik* o2)
{
    return o1->przystosowanie>o2->przystosowanie;
}

void AlgorytmGenetyczny::selekcja()
{
    //  std::cout<<"Selekcja "<<std::endl;
    qSort(populacja->populacja->begin(),populacja->populacja->end(),osobnikSelect);



    std::cout<<"write to file"<<std::endl;
    QFile file("out.txt");
    if (!file.open(QIODevice::Append| QIODevice::Text))
        return;

    int srednia=0;

    foreach(Osobnik* os, *populacja->populacja)
    {
        srednia+=os->przystosowanie;
    }

    srednia/=populacja->populacja->size();

    QTextStream out(&file);
    out <<pokolenie<< " Najlepszy: "<<populacja->populacja->at(0)->przystosowanie<<" Najgorszy: "
       <<populacja->populacja->at(populacja->populacja->size()-1)->przystosowanie<<" Srednia: "<<srednia<<"\n";

    file.close();

}
