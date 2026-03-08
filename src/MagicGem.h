#ifndef MAGICGEM_H
#define MAGICGEM_H

#include "GameObject.h"
#include "Maze.h"
#include <cstdlib>

class MagicGem : public GameObject 
{
    public:
        MagicGem(int x, int y) : GameObject(x, y, 'G', 3) {} // Color 3: Red

        void teleport(Maze &maze);
        void draw() override;
};

#endif