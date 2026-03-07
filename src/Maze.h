#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include <string>

class Maze
{
    private:
        std::vector<std::string> grid;
        int rows;
        int cols;
    
    public:
        bool loadFromFile(std::string filename);
        void draw();

        bool isWall(int y, int x);

        int getRows();
        int getCols();
};

#endif