#include "populacja.h"

Populacja::Populacja(int r)
{
    rozmiar=r;

    qsrand(time(NULL));

    populacja = new QVector<Osobnik*>;

    for(int i=0; i<rozmiar; ++i)
    {
        int g1=qrand()%8+1;
        int g2=qrand()%8+1;
        int g3=qrand()%8+1;
        int g4=qrand()%8+1;
        int g5=qrand()%8+1;
        int g6=qrand()%8+1;
        int g7=qrand()%8+1;
        int g8=qrand()%8+1;

        populacja->push_front(new Osobnik(g1,g2,g3,g4,g5,g6,g7,g8));
       // std::cout<<g1<<" "<<g2<<" "<<g3<<" "<<g4<<" "<<g5<<" "<<g6<<" "<<g7<<" "<<g8<<std::endl;
       // std::cout<<"size "<<populacja->size()<<std::endl;
    }
}
