#ifndef ALGORYTMGENETYCZNY_H
#define ALGORYTMGENETYCZNY_H

#include "populacja.h"


class AlgorytmGenetyczny
{
public:
    AlgorytmGenetyczny(Populacja *pop);

    void mutacja();
    void krzyzowanie();
    void transpozycja();
    void nowaPopulcacja();
    void ocenaOsobnikow();
    void selekcja();

    Osobnik* osobnik(int os);

    void update()
    {
       // std::cout<<"Update "<<std::endl;
        //ocenaOsobnikow();
        selekcja();
        krzyzowanie();
        mutacja();

        ++pokolenie;
        nowaPopulcacja();
    }

    int pokolenie;

private:
    Populacja* populacja;

};

#endif // ALGORYTMGENETYCZNY_H
