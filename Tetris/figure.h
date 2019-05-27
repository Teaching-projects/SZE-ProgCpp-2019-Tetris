#include <SFML/Graphics.hpp>
#include "cell.h"
#ifndef FIGURE_H
#define FIGURE_H

#define WIDTH 10
#define HEIGHT 20

using namespace sf;

enum Direction {UP, RIGHT, DOWN, LEFT};

class Figure
{
    public:
        Figure(int type);
        virtual ~Figure();

        bool moveFigure(Cell cells[WIDTH][HEIGHT], Direction direction);    //mozgatja az elemet le + gombnyomásra másfele is
        bool rotateFigure(Cell cells[WIDTH][HEIGHT]);                       //alakzat forgatása

    protected:

    private:
        int coordinates[4][2];              //az alakzat celláinak koordinátái: 4x2 es int mátrix
        Color color;                        //az alakzat színe
        int figureType;                           //az alakzat típusa  --  milyen alakú forma
                                            /*  0- L
                                                1- J
                                                2- O
                                                3- T
                                                4- I
                                                5- Z
                                                6- S
                                            */
        bool isCellOk(int coordinatePair[2]);                             //benne van-e a kereten belül?
        bool isCellOk(int coordinatePair[2], Direction direction);        //esemény hatására is bent marad e?

};

#endif // FIGURE_H
