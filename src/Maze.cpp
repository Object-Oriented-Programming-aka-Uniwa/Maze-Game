#include "Maze.h"
#include <fstream>
#include <ncurses.h>

bool Maze::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    std::string line;
    while (getline(file, line))
    {
        grid.push_back(line);
    }

    height = grid.size();
    width = grid[0].size();
    return true;
}

bool Maze::isWalkable(int x, int y) const
{
    if (y < 0 || y >= height || x < 0 || x >= width) return false;
    return grid[y][x] == '.';
}

void Maze::draw()
{
    for (int i = 0; i < height; ++i)
    {
        mvprintw(i, 0, grid[i].c_str());
    }
}

void Maze::getRandomFreeSpace(int &outX, int &outY)
{
    do
    {
        outX = std::rand() % width;
        outY = std::rand() % height;
    } 
    while (!isWalkable(outX, outY));
}