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

    Osobnik* osobnik();

    void update()
    {
       // std::cout<<"Update "<<std::endl;
        ocenaOsobnikow();
        selekcja();
        krzyzowanie();
        mutacja();

        ++pokolenie;
        nowaPopulcacja();
    }

private:
    Populacja* populacja;
    int pokolenie;
};

#endif // ALGORYTMGENETYCZNY_H
