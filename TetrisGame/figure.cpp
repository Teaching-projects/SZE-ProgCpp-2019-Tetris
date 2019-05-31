#include "figure.h"

Figure::Figure(int type)
{
  figureType = type;
  if (type == 0)
    {
      coordinates[0][0] = WIDTH/2 - 1;      //    0  1  2  3  4  5  6  7
      coordinates[0][1] = 1;                //  0                   *
                                            //  1             *  *  *
      coordinates[1][0] = WIDTH/2 + 1;      //  2
      coordinates[1][1] = 0;                //  3
                                            //  4
      coordinates[2][0] = WIDTH/2;          //  5
      coordinates[2][1] = 1;                //  6
                                            //  7
      coordinates[3][0] = WIDTH/2 + 1;      //  8
      coordinates[3][1] = 1;                //  9

      color = Color::Blue;
    }
    else if (type == 1)
    {
      coordinates[0][0] = WIDTH/2 - 1;      //    0  1  2  3  4  5  6  7
      coordinates[0][1] = 0;                //  0             *  *  *
                                            //  1                   *
      coordinates[1][0] = WIDTH/2 + 1;      //  2
      coordinates[1][1] = 1;                //  3
                                            //  4
      coordinates[2][0] = WIDTH/2;          //  5
      coordinates[2][1] = 0;                //  6
                                            //  7
      coordinates[3][0] = WIDTH/2 + 1;      //  8
      coordinates[3][1] = 0;                //  9

      color = Color::Blue;
    }
    else if (type == 2)
    {
      coordinates[0][0] = WIDTH/2 - 1;      //    0  1  2  3  4  5  6  7
      coordinates[0][1] = 0;                //  0             *  *
                                            //  1             *  *
      coordinates[1][0] = WIDTH/2;          //  2
      coordinates[1][1] = 0;                //  3
                                            //  4
      coordinates[2][0] = WIDTH/2 - 1;      //  5
      coordinates[2][1] = 1;                //  6
                                            //  7
      coordinates[3][0] = WIDTH/2;          //  8
      coordinates[3][1] = 1;                //  9

      color = Color::Red;
    }
    else if (type == 3)
    {
      coordinates[0][0] = WIDTH/2 - 1;      //    0  1  2  3  4  5  6  7
      coordinates[0][1] = 0;                //  0             *  *  *
                                            //  1                *
      coordinates[1][0] = WIDTH/2;          //  2
      coordinates[1][1] = 1;                //  3
                                            //  4
      coordinates[2][0] = WIDTH/2 + 1;      //  5
      coordinates[2][1] = 0;                //  6
                                            //  7
      coordinates[3][0] = WIDTH/2;          //  8
      coordinates[3][1] = 0;                //  9

      color = Color::Magenta;
    }
    else if (type == 4)
    {
      coordinates[0][0] = WIDTH/2 - 2;      //    0  1  2  3  4  5  6  7
      coordinates[0][1] = 1;                //  0
                                            //  1          *  *  *  *
      coordinates[1][0] = WIDTH/2 + 1;      //  2
      coordinates[1][1] = 1;                //  3
                                            //  4
      coordinates[2][0] = WIDTH/2 - 1;      //  5
      coordinates[2][1] = 1;                //  6
                                            //  7
      coordinates[3][0] = WIDTH/2;          //  8
      coordinates[3][1] = 1;                //  9

      color = Color::Yellow;
    }
    else if (type == 5)
    {
      coordinates[0][0] = WIDTH/2 - 1;      //    0  1  2  3  4  5  6  7
      coordinates[0][1] = 0;                //  0             *  *
                                            //  1                *  *
      coordinates[1][0] = WIDTH/2 + 1;      //  2
      coordinates[1][1] = 1;                //  3
                                            //  4
      coordinates[2][0] = WIDTH/2;          //  5
      coordinates[2][1] = 0;                //  6
                                            //  7
      coordinates[3][0] = WIDTH/2;          //  8
      coordinates[3][1] = 1;                //  9

      color = Color::Green;
    }
    else if (type == 6)
    {
      coordinates[0][0] = WIDTH/2 - 1;      //    0  1  2  3  4  5  6  7
      coordinates[0][1] = 1;                //  0                *  *
                                            //  1             *  *
      coordinates[1][0] = WIDTH/2 + 1;      //  2
      coordinates[1][1] = 0;                //  3
                                            //  4
      coordinates[2][0] = WIDTH/2;          //  5
      coordinates[2][1] = 0;                //  6
                                            //  7
      coordinates[3][0] = WIDTH/2;          //  8
      coordinates[3][1] = 1;                //  9

      color = Color::Green;
    }
}


Figure::~Figure()
{
    //dtor
}

bool Figure::isCellOk(int coordinatePair[2])
{
  if (coordinatePair[0] >= WIDTH or coordinatePair[0] < 0 or coordinatePair[1] >= HEIGHT or coordinatePair[1] < 0)
    {
      return false;
    }
  return true;
}

bool Figure::isCellOk(int coordinatePair[2], Direction direction)
{
  int updateX, updateY;
  if (direction == DOWN)
  {
      updateX = 0;
      updateY = 1;
  } else if (direction == RIGHT)
  {
      updateX = 1;
      updateY = 0;
  } else if (direction == LEFT)
  {
      updateX = -1;
      updateY = 0;
  }

  if (coordinatePair[0] + updateX >= WIDTH or coordinatePair[0] + updateX < 0 or coordinatePair[1] + updateY >= HEIGHT or coordinatePair[1] + updateY < 0)
  {
      return false;
  }
  return true;
}

bool Figure::moveFigure(Cell cells[WIDTH][HEIGHT], Direction direction)
{
  int updateX, updateY;
  if (direction == DOWN)
  {
      updateX = 0;
      updateY = 1;
  } else if (direction == RIGHT)
  {
      updateX = 1;
      updateY = 0;
  } else if (direction == LEFT)
  {
      updateX = -1;
      updateY = 0;
  }

  for (int i = 0; i < 4; i++)
    {
      cells[coordinates[i][0]][coordinates[i][1]].setFree(false);         //az elem a jelenlegi helyén ne legyen látható
    }

  bool doUpdate = true;
  for (int j = 0; j < 4; j++)
    {
      if (cells[coordinates[j][0] + updateX][coordinates[j][1] + updateY].isFree() or !isCellOk(coordinates[j], direction))
	{           //ahova mozogna az látszik, vagyis már van ott valami               vagy    kimenne a mezõbõl a blokk
	  doUpdate = false;         //akkor ne frissítsen
	}   //ezt az elem minden kockájára csinálja meg
    }
  if (doUpdate == true)
    {
      for (int k = 0; k < 4; k++)       //ha frissítenie kell akkor mindegyik blokkrész koordinátáját mozgatja (hozzáadja az updateX/Y-t)
	{
	  coordinates[k][0] += updateX;
	  coordinates[k][1] += updateY;
	}
    }

    for (int i = 0; i < 4; i++)
    {
      cells[coordinates[i][0]][coordinates[i][1]].setFree(true);
      cells[coordinates[i][0]][coordinates[i][1]].setColor(color);
    }

  return doUpdate;      //ha nem lett frissítve -> false értéket ad (jöhet a következõ)
}

bool Figure::rotateFigure(Cell cells[WIDTH][HEIGHT])
{
    if(figureType != 2){
      int tempCoord[4][2];                      //ideiglenes koordináta tömb    (1. az x koordináta, 2. az y)
      tempCoord[3][0] = coordinates[3][0];      //ekörül a pont körül forgatunk
      tempCoord[3][1] = coordinates[3][1];
      for (int i = 0; i < 3; i++)
        {
          tempCoord[i][0] = coordinates[3][0] + (coordinates[3][1] - coordinates[i][1]);
          tempCoord[i][1] = coordinates[3][1] - (coordinates[3][0] - coordinates[i][0]);
        }
    //eltünteti a blokkot
      for (int i = 0; i < 4; i++)
        {
          cells[coordinates[i][0]][coordinates[i][1]].setFree(false);
        }
        //ugyanaz mint az update-nél
      bool doUpdate = true;
      for (int j = 0; j < 4; j++)
        {
          if (cells[tempCoord[j][0]][tempCoord[j][1]].isFree() or !isCellOk(tempCoord[j]))
        {
          doUpdate = false;

        }
        }
      if (doUpdate == true)
        {
          for (int k = 0; k < 4; k++)
        {
          coordinates[k][0] = tempCoord[k][0];
          coordinates[k][1] = tempCoord[k][1];
        }
        }


        for (int i = 0; i < 4; i++)
        {
          cells[coordinates[i][0]][coordinates[i][1]].setFree(true);
          cells[coordinates[i][0]][coordinates[i][1]].setColor(color);
        }
      return doUpdate;
    } else {
        return true;
    }
}

