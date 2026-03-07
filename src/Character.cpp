#include "Character.h"
#include <ncurses.h>

Character::Character(int x, int y, char s)
{
    this->x = x;
    this->y = y;
    symbol = s;
}

void Character::draw()
{
    mvaddch(y, x, symbol);
}

void Character::move(int dx, int dy, Maze &maze)
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

int Character::getX()
{
    return x;
}

int Character::getY()
{
    return y;
}
