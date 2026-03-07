#ifndef CHARACTER_H
#define CHARACTER_H

#include "Maze.h"

class Character
{
    protected:
        int x;
        int y;
        char symbol;
    
    public:
        Character(int x, int y, char s);

        void draw();
        void move(int dx, int dy, Maze &maze);

        int getX();
        int getY();
};
 
#endif