#ifndef PETRI_H
#define PETRI_H

#include "Maze.h"

class Petri
{
    private:
        int x;
        int y;
    
    public:
        Petri();
    
        void setPosition(int x, int y);
        void draw();

        int getX();
        int getY();

        void move(int dx, int dy, Maze &maze);
};

#endif