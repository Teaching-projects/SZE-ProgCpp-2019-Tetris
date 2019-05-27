#include "cell.h"

Cell::Cell()
{
    //ctor
}

Cell::~Cell()
{
    //dtor
}

void Cell::setColor(Color newColor)
{
  color = newColor;
}

Color Cell::getColor()
{
  return color;
}

void Cell::setFree(bool newFree)
{
    free = newFree;
}

bool Cell::isFree()
{
    return free;
}
