#include "algorytmgenetyczny.h"
//#include <algorithm>
#include <qalgorithms.h>

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

void AlgorytmGenetyczny::transpozycja()
{

}

void AlgorytmGenetyczny::nowaPopulcacja()
{

   // std::cout<<"pokolenie "<<pokolenie<<std::endl;
    if(pokolenie>15)
    {
    //    std::cout<<"stwurz nowa populacje"<<std::endl;
        pokolenie=0;
    }
}

void AlgorytmGenetyczny::ocenaOsobnikow()
{
   // std::cout<<"Ocena osobnika "<<std::endl;
}

bool osobnikSelect(Osobnik* o1, Osobnik* o2)
{
    return o1->przystosowanie<o2->przystosowanie;
}

void AlgorytmGenetyczny::selekcja()
{
  //  std::cout<<"Selekcja "<<std::endl;
    qSort(populacja->populacja->begin(),populacja->populacja->end(),osobnikSelect);
}
