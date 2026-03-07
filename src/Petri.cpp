#include "Petri.h"
#include <ncurses.h>

Petri::Petri()
{
    x = 0;
    y = 0;
}

void Petri::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Petri::draw()
{
    mvaddch(y, x, 'P');
}

void Petri::move(int dx, int dy, Maze &maze)
{
    int newX, newY;

    newX = x + dx;
    newY = y + dy;

    if (!maze.isWall(newY, newX))
    {
        x = newX;
        y = newY;
    }
}

int Petri::getX()
{
    return x;
}

int Petri::getY()
{
    return y;
}