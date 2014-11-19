#include "Game.hpp"

Game::Game() {
    application = new glut::Application();
    window = new glut::GameWindow();
    windowParameters = glut::WindowParameters(
        "Asteriods",
        Point2i(200, 100),
        Size2i(640, 480),
        true
    );

    world = new World();
    level = new Level(world, Rectanglef(-20.0f, -20.0f, 20.0f, 20.0f));
}

Game::~Game() {
    delete level;
    delete world;
    delete window;
    delete application;
}

void Game::initialize(int argc, char** argv) {
    application->initialize(argc, argv);
    application->addWindow(window, windowParameters);
}

void Game::start() {
    auto sceneManager = window->getSceneManager();
    auto levelScene = new LevelScene(sceneManager, world->getEventBus(), level);

    sceneManager->add(levelScene);
    sceneManager->setCurrent(levelScene);

    application->run();
}
