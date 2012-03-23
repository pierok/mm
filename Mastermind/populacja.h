#ifndef POPULACJA_H
#define POPULACJA_H

#include <QVector>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include "osobnik.h"


class Populacja
{
public:
    Populacja(int r);
    inline int getRozmiar()
    {
        return rozmiar;
    }

    inline void nowaPopulacja(QVector<Osobnik*>* nowa)
    {
        //delete populacja;
        populacja=nowa;
    }

    QVector<Osobnik*>* populacja;
private:
    int rozmiar;
};

#endif // POPULACJA_H
