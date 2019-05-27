#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "cell.h"
#include "figure.h"

#define TETRIS_BOX_SIZE 40
#define GAME_SPEED 4
#define WIDTH 10
#define HEIGHT 20

class Game
{
    public:
        Game();
        virtual ~Game();
        bool stopFigure(Figure& figure, RenderWindow& window);
        void checkRows();
        void drawCells(RenderWindow& window);
        bool gameOver();
        int getScore();

    protected:

    private:
        Cell cells[WIDTH][HEIGHT];
        int curFrame;
        int score;
};

#endif // GAME_H
