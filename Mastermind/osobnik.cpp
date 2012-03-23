#include "osobnik.h"

Osobnik::Osobnik(int g1, int g2, int g3, int g4, int g5, int g6, int g7, int g8)
{
    genom[0]=g1;
    genom[1]=g2;
    genom[2]=g3;
    genom[3]=g4;
    genom[4]=g5;
    genom[5]=g6;
    genom[6]=g7;
    genom[7]=g8;

    przystosowanie=0;
}

void Osobnik::newGenoem(int g1, int g2, int g3, int g4, int g5, int g6, int g7, int g8)
{
    genom[0]=g1;
    genom[1]=g2;
    genom[2]=g3;
    genom[3]=g4;
    genom[4]=g5;
    genom[5]=g6;
    genom[6]=g7;
    genom[7]=g8;

    przystosowanie=0;
}

void Osobnik::reset()
{
    genom[0]=0;
    genom[1]=0;
    genom[2]=0;
    genom[3]=0;
    genom[4]=0;
    genom[5]=0;
    genom[6]=0;
    genom[7]=0;

    przystosowanie=0;
}
