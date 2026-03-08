#include "MagicGem.h"
#include "Maze.h"
#include <ncurses.h>

void MagicGem::teleport(Maze &maze)
{
    int newX, newY;

    maze.getRandomFreeSpace(newX, newY);
    this->x = newX;
    this->y = newY;
}

void MagicGem::draw()
{
    attron(COLOR_PAIR(3));
    mvaddch(y, x, 'G');
    attroff(COLOR_PAIR(3));
}