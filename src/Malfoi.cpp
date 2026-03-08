#include "Malfoi.h"
#include "Maze.h"
#include <cmath>
#include <ncurses.h>

void Malfoi::moveSmart(int targetX, int targetY, Maze &maze)
{
    int bestX = x, bestY = y;
    double minDistance = 1e9;

    // Check all 4 possible directions (Up, Down, Left, Right)
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (maze.isWalkable(nx, ny))
        {
            double dist = std::sqrt(std::pow(nx - targetX, 2) + std::pow(ny - targetY, 2));
            if (dist < minDistance)
            {
                minDistance = dist;
                bestX = nx; bestY = ny;
            }
        }
    }

    x = bestX; y = bestY;
}

void Malfoi::draw()
{
    attron(COLOR_PAIR(colorPair));
    mvaddch(y, x, symbol);
    attroff(COLOR_PAIR(colorPair));
}