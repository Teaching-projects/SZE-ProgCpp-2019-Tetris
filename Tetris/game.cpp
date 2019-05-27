#include "game.h"

Game::Game()
{
    srand(time(NULL));
    for (int i = 0; i < WIDTH; i++)
    {
      for (int j = 0; j < HEIGHT; j++)
      {
      cells[i][j].setFree(false);
      }
    }

    RenderWindow window(VideoMode(WIDTH * TETRIS_BOX_SIZE, (HEIGHT - 2) * TETRIS_BOX_SIZE), "Tetris");
    window.setVerticalSyncEnabled(true);              //függõleges szinkronizálás engedélyezése
    window.setFramerateLimit(WIDTH);                  //filmkockák száma bizonyos idõ alatt -- újratöltés gyorsasága -- ábrák sebessége

    Figure figure(rand() % 7);
    curFrame = 0;
    score = 0;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
          if (event.type == Event::Closed)
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            figure.moveFigure(cells, LEFT);
        } else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            figure.moveFigure(cells, RIGHT);
        } else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            figure.rotateFigure(cells);
        } else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            if(stopFigure(figure, window)){
                Figure newFigure(rand() % 7);
                figure = newFigure;
            }
        }

        if (curFrame == GAME_SPEED)
        {
            curFrame = 0;
            if(stopFigure(figure, window))
            {
                Figure newFigure(rand() % 7);
                figure = newFigure;
            }

        } else
        {
            curFrame++;
        }

        window.clear(Color::White);
        drawCells(window);
        window.display();
    }
}

Game::~Game()
{
    //dtor
}

bool Game::stopFigure(Figure& figure, RenderWindow& window)
{
  if (!figure.moveFigure(cells, DOWN))
    {
      checkRows();
      if (gameOver())
	{
	  window.close();
	  printf("Game Over!\n");
	  printf("Score: %d\n", getScore());
	}
        return true;
    } else {
        return false;
    }
}

void Game::checkRows()
{
    int newScore = 0;
    bool check;
    int xPos;
    for(int i = (HEIGHT - 1); i >= 2; i--)
    {
        xPos = 0;
        check = true;
        while(check == true)
        {
            if (xPos == WIDTH)
            {
                newScore++;
                for (int j = i; j >= 1; j--)
                {
                    for (int k = 0; k < WIDTH; k++)
                    {
                        if (cells[k][j - 1].isFree())
                        {
                            cells[k][j].setColor(cells[k][j - 1].getColor());
                            cells[k][j - 1].setFree(false);
                            cells[k][j].setFree(true);
                        }
                        else
                        cells[k][j].setFree(false);
                    }

                }
                i++;
                check = false;
            }
            else if (!cells[xPos][i].isFree())
            {
                check = false;
            }
            else
            {
                xPos++;
            }
        }
    }

    score = score + newScore * newScore;
}

void Game::drawCells(RenderWindow& window)
{
    RectangleShape rectangle(Vector2f(TETRIS_BOX_SIZE, TETRIS_BOX_SIZE));     //téglalapok kirajzolására szolgáló dolgok kétdimenziós tömbben
    int xPos = 0;
    int yPos = -2 * TETRIS_BOX_SIZE;

    for (int j = 0; j < HEIGHT; j++)
    {
        xPos = 0;
        for (int i = 0; i < WIDTH; i++)
        {
            if (cells[i][j].isFree())
            {
              rectangle.setFillColor(cells[i][j].getColor());
              rectangle.setPosition(xPos, yPos);
              window.draw(rectangle);
            }
            xPos = xPos + TETRIS_BOX_SIZE;
        }
        yPos = yPos + TETRIS_BOX_SIZE;
    }
}

bool Game::gameOver()
{
    for (int i = 0; i < WIDTH; i++)
    {
        if (cells[i][1].isFree())
        {
            return true;
        }
    }
    return false;
}

int Game::getScore()
{
    return score;
}
