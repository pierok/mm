#ifndef MEMENTO_H
#define MEMENTO_H

class Memento
{
public:
    Memento();
    ~Memento(){}

    inline void setPresented(int i, int w)
    {
        presented[i]=w;
    }
    inline void setResult(int i, int w)
    {
        result[i]=w;
    }

    inline int getPresented(int i)
    {
        return presented[i];
    }

    inline int getResult(int i)
    {
        return result[i];
    }

    inline void setBlack(int i)
    {
        black=i;
    }

    inline void setWhite(int i)
    {
        white=i;
    }

    inline int getBlack()
    {
        return black;
    }

    inline int getWhite()
    {
        return white;
    }

private:
    int presented[8];
    int result[8];
    int black;
    int white;
};

#endif // MEMENTO_H
