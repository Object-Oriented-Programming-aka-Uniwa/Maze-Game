#include "GameEngine.h"
#include <iostream>
#include <ctime>

int main(int argc, char **argv)
{
    // Check if the maze file was provided as a command line arg
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " maps/maze_file.txt" << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    try
    {
        GameEngine game(argv[1]);
        game.init();
        game.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
