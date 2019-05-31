#ifndef CELL_H
#define CELL_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Cell                  //cellák -- ezekbõl áll a tábla
{
    public:
        Cell();
        virtual ~Cell();

        void setColor(Color newColor);        //szín beállítása
        Color getColor();                     //szín lekérdezése

        void setFree(bool newFree);     //cella állapotának beállítása (legyen szabad/foglalt)
        bool isFree();                  //állapot lekérdezése (szabad/foglalt)

    protected:

    private:
        Color color;        //valamilyen színûek
        bool free;
};

#endif // CELL_H
