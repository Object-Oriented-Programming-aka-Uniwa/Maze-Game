#include "Poteridis.h"
#include "Maze.h"
#include <ncurses.h>

void Poteridis::move(int inputKey, Maze &maze)
{
    int nextX = x, nextY = y;

    switch(inputKey)
    {
        case KEY_UP     : nextY--; break;
        case KEY_DOWN   : nextY++; break;
        case KEY_LEFT   : nextX--; break;
        case KEY_RIGHT  : nextX++; break;
        case ' '        : return; // stay still
    }

    if (maze.isWalkable(nextX, nextY))
    {
        x = nextX; 
        y = nextY;
    }
}

void Poteridis::draw()
{
    attron(COLOR_PAIR(colorPair));
    mvaddch(y, x, symbol);
    attroff(COLOR_PAIR(colorPair));
}