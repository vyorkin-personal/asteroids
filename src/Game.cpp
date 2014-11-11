#include "Game.hpp"

Game::Game() {
    application = new glut::Application();
    window = new glut::GameWindow();
    windowParameters = glut::WindowParameters("Asteriods",
        Point2i(10, 10), Size(640, 480), false);
}

Game::~Game() {
    delete window;
    delete application;
}

void Game::initialize(int argc, char** argv) {
    application->initialize(argc, argv);
    application->addWindow(window, windowParameters);
}

void Game::start() {
    auto levelScene = new LevelScene(window->getSize());
    auto sceneManager = window->getSceneManager();

    sceneManager->add(levelScene);
    sceneManager->setCurrent(levelScene);

    application->run();
}
