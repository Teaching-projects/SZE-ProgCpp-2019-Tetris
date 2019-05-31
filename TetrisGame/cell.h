#ifndef CELL_H
#define CELL_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Cell                  //cell�k -- ezekb�l �ll a t�bla
{
    public:
        Cell();
        virtual ~Cell();

        void setColor(Color newColor);        //sz�n be�ll�t�sa
        Color getColor();                     //sz�n lek�rdez�se

        void setFree(bool newFree);     //cella �llapot�nak be�ll�t�sa (legyen szabad/foglalt)
        bool isFree();                  //�llapot lek�rdez�se (szabad/foglalt)

    protected:

    private:
        Color color;        //valamilyen sz�n�ek
        bool free;
};

#endif // CELL_H
