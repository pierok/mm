#ifndef OSOBNIK_H
#define OSOBNIK_H

class Osobnik
{
public:
    Osobnik(int g1, int g2, int g3, int g4, int g5, int g6, int g7, int g8);
    void newGenoem(int g1, int g2, int g3, int g4, int g5, int g6, int g7, int g8);
    void reset();

    int genom[8];
    int przystosowanie;


};

#endif // OSOBNIK_H
