#include "GameObject.h"
#include <ncurses.h>

void GameObject::draw()
{
    attron(COLOR_PAIR(colorPair));
    mvaddch(y, x, symbol);
    attroff(COLOR_PAIR(colorPair));
}