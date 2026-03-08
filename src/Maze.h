#ifndef MAZE_H
#define MAZE_H

#include "GameObject.h"
#include <vector>
#include <string>

class Maze 
{
    private:
        std::vector<std::string> grid;
        int height, width;
    
    public:
        bool loadFromFile(const std::string &filename);
        bool isWalkable(int x, int y) const;
        void getRandomFreeSpace(int &outX, int &outY);
        void draw();
};

#endif