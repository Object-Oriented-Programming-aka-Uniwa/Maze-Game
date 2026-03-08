#ifndef POTERIDIS_H
#define POTERIDIS_H

#include "GameObject.h"
#include "Maze.h"

class Poteridis : public GameObject
{
    public:
        Poteridis(int x, int y) : GameObject(x, y, 'M', 1) {} // Color 1: Orange

        void move(int key, Maze& maze);
        void draw() override;
};

#endif