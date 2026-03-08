#ifndef MALFOI_H
#define MALFOI_H

#include "GameObject.h"
#include "Maze.h"

class Malfoi : public GameObject
{
    public:
        Malfoi(int x, int y) : GameObject(x, y, 'L', 2) {} // Color 2: Green

        void moveSmart(int targetX, int targetY, Maze &maze);
        void draw() override;
};

#endif