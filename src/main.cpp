#include <ncurses.h>
#include <cstdlib>
#include <ctime>

#include "Maze.h"
#include "Character.h"
#include "Petri.h"

int main()
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    // COLORS
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK); // M (orange-like)
    init_pair(2, COLOR_GREEN, COLOR_BLACK);  // L
    init_pair(3, COLOR_RED, COLOR_BLACK);    // P

    srand(time(NULL));

    Maze maze;
    maze.loadFromFile("mazes/maze.txt");

    Character babis(1, 1, 'M');
    Character loukas(3, 3, 'L');

    Petri petri;
    petri.setPosition(5, 5);

    int ch;

    while (true)
    {
        clear();

        maze.draw();

        // draw Petri
        attron(COLOR_PAIR(3));
        petri.draw();
        attroff(COLOR_PAIR(3));

        // draw babis
        attron(COLOR_PAIR(1));
        babis.draw();
        attroff(COLOR_PAIR(1));

        // draw loukas
        attron(COLOR_PAIR(2));
        loukas.draw();
        attroff(COLOR_PAIR(2));

        refresh();

        ch = getch();

        if (ch == 27) break;

        switch(ch)
        {
            case KEY_UP:
                babis.move(0, -1, maze);
                break;
            case KEY_DOWN:
                babis.move(0, 1, maze);
                break;
            case KEY_LEFT:
                babis.move(-1, 0, maze);
                break;
            case KEY_RIGHT:
                babis.move(1, 0, maze);
                break;
        }

        // Loukas random movement
        int r = rand() % 4;

        if (r == 0) loukas.move(1, 0, maze);
        if (r == 1) loukas.move(-1, 0, maze);
        if (r == 2) loukas.move(0, 1, maze);
        if (r == 3) loukas.move(0, -1, maze);

        // Petri random movement
        int pr = rand() % 4;

        if (pr == 0) petri.move(1, 0, maze);
        if (pr == 1) petri.move(-1, 0, maze);
        if (pr == 2) petri.move(0, 1, maze);
        if (pr == 3) petri.move(0, -1, maze);

        // Win conditions
        if (babis.getX() == petri.getX() && babis.getY() == petri.getY())
        {
            mvprintw(maze.getRows() + 1, 0, "Babis wins!");
            refresh();
            getch();
            break;
        }

        if (loukas.getX() == petri.getX() && loukas.getY() == petri.getY())
        {
            mvprintw(maze.getRows() + 1, 0, "Loukas wins!");
            refresh();
            getch();
            break;
        }
    }

    endwin();

    return 0;
}