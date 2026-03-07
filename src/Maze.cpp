#include "Maze.h"
#include <fstream>
#include <ncurses.h>

bool Maze::loadFromFile(std::string filename)
{
    std::ifstream file(filename);
    std::string line;
    
    if (!file) return false;

    while (getline(file, line))
        grid.push_back(line);  
    
    rows = grid.size();
    cols = grid[0].size();

    return true;
}

void Maze::draw()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mvaddch(i, j, grid[i][j]);
}

bool Maze::isWall(int y, int x)
{
    return grid[y][x] == '*';
}

int Maze::getRows()
{
    return rows;
}

int Maze::getCols()
{
    return cols;
}