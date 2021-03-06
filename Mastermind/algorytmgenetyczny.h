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
    void selekcja();

    Osobnik* osobnik(int os);

    void update()
    {
        selekcja();
        krzyzowanie();
        mutacja();
        transpozycja();

        ++pokolenie;
        if(pokolenie>=50)
        {
           // nowaPopulcacja();
        }
    }

    int pokolenie;

private:
    Populacja* populacja;

};

#endif // ALGORYTMGENETYCZNY_H
