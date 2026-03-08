#include "GameEngine.h"
#include <ncurses.h>

GameEngine::GameEngine(const std::string& mapFile)
{
    isRunning = true;
    gameOver = false;

    if (!maze.loadFromFile(mapFile))
    {
        isRunning = false;
    }

    int x, y;

    maze.getRandomFreeSpace(x, y);
    babis = new Poteridis(x, y);

    maze.getRandomFreeSpace(x, y);
    loukas = new Malfoi(x, y);

    maze.getRandomFreeSpace(x, y);
    gem = new MagicGem(x, y);
}

GameEngine::~GameEngine()
{
    delete babis;
    delete loukas;
    delete gem;
}

void GameEngine::init()
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK); // Poteridis
    init_pair(2, COLOR_GREEN, COLOR_BLACK); // Malfoi
    init_pair(3, COLOR_RED, COLOR_BLACK); // Gem 
}

void GameEngine::run()
{
    while (isRunning)
    {
        maze.draw();
        gem->draw();
        babis->draw();
        loukas->draw();
        refresh();

        int ch = getch();
        if (ch == 27) break; // Ecape key

        // 1. Process Poteridis
        babis->move(ch, maze);

        // 2. Process Malfoi (Smart Move)
        loukas->moveSmart(gem->getX(), gem->getY(), maze);

        // 3. Randomly teleport Gem
        if (rand() % 10 == 0) gem->teleport(maze);

        checkWin();
    }
    endwin();
}

void GameEngine::checkWin()
{
    if (babis->getX() == gem->getX() && babis->getY() == gem->getY())
    {
        showGameOver("Babis Poteridis Wins!");
    }
    else if (loukas->getX() == gem->getX() && loukas->getY() == gem->getY())
    {
        showGameOver("Loukas Malfoi Wins!");
    }
}

void GameEngine::showGameOver(const std::string& message)
{
    clear();

    int row, col;
    getmaxyx(stdscr, row, col);

    mvprintw(row / 2, (col - message.length()) / 2, "%s", message.c_str());
    mvprintw(row / 2 + 2, (col - 30) / 2, "Press ENTER to Try Again");
    mvprintw(row / 2 + 3, (col - 30) / 2, "Press ESCAPE to Exit");
    refresh();

    while (true)
    {
        int ch = getch();
        if (ch == 10 || ch == KEY_ENTER)
        {
            resetGame();
            break;
        }
        else if (ch == 27)
        {
            isRunning = false;
            break;
        }
    }
}

void GameEngine::resetGame()
{
    int x, y;

    maze.getRandomFreeSpace(x, y);
    babis->setPosition(x, y);

    maze.getRandomFreeSpace(x, y);
    loukas->setPosition(x, y);

    maze.getRandomFreeSpace(x, y);
    gem->setPosition(x, y);

    clear();
}