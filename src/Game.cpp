#include "Game.hpp"

Game::Game() {
    application = new glut::Application();
    window = new glut::GameWindow();
}

Game::~Game() {
    delete window;
    delete application;
}

void Game::initialize(int argc, char** argv) {
    application->initialize(argc, argv);
    application->addWindow(window);
}

void Game::start() {
    auto levelScene = new LevelScene();
    auto sceneManager = window->getSceneManager();

    sceneManager->add(levelScene);
    sceneManager->setCurrent(levelScene);

    application->run();
}
