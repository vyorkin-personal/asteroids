#include "Base.hpp"
#include "Game.hpp"

int main(int argc, char* argv[]) {
    Game game;

    game.initialize(argc, argv);
    game.start();

    return 0;
}
