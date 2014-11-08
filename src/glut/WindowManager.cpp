#include "glut/WindowManager.hpp"

namespace glut {
    WindowManager::~WindowManager() {
        destroyAll();
    }

    Window* WindowManager::add(Window* window, const WindowParameters& params) {
        glutInitWindowPosition(params.position.x, params.position.y);
        glutInitWindowSize(params.size.x, params.size.y);
        
        id = glutCreateWindow(params.title.c_str());
        windows.insert(std::make_pair(id, window));

        return window;
    }

    void WindowManager::destroy(Window* window) {
        destroy(window->getId());
    }

    void WindowManager::destroy(const int windowId) {
        const auto it = windows.find(windowId);
        if (it != windows.cend()) {
            it->second->onDestroy();
            glutDestroyWindow(it->first);
            delete it->second;
            windows.erase(it);
        }
    }

    void WindowManager::destroyAll() {
        for (auto& it: windows) {
            it.second->onDestroy();
            glutDestroyWindow(it.first);
            delete it.second;
        }
        windows.clear();
    }

    Window* WindowManager::getCurrent() const {
        const int id = glutGetWindow();
        const auto it = windows.find(id);

        return it == windows.cend() ?
            nullptr : it->second;
    }

    void WindowManager::setCurrent(Window* window) {
        glutSetWindow(window->getId());
    }
}
