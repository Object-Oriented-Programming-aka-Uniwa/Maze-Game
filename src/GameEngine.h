#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Maze.h"
#include "Poteridis.h"
#include "Malfoi.h"
#include "MagicGem.h"

class GameEngine 
{
    private:
        Maze maze;
        Poteridis* babis;
        Malfoi* loukas;
        MagicGem* gem;
        bool isRunning;
        bool gameOver;
    
    public:
        GameEngine(const std::string& mapFile);
        ~GameEngine();

        void init();
        void run();
        void checkWin();
        void showGameOver(const std::string& message);
        void resetGame();
};

#endif