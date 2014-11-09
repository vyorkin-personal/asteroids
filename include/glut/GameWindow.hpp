#pragma once

#include "Base.hpp"
#include "glut/Window.hpp"
#include "scene/SceneManager.hpp"

namespace glut {
    class GameWindow: public Window {
        public:
            GameWindow();
            ~GameWindow();

            SceneManager* getSceneManager() const {
                return sceneManager;
            }

            virtual void onResize(const Size& size) override;
            virtual void onRender() override;
            virtual void onDestroy() override;
            virtual void onShow() override;
            virtual void onHide() override;

            virtual void onMouseEnter() override;
            virtual void onMouseLeave() override;
            virtual void onMouseButtonDown(const MouseButton button, const Point2i& position) override;
            virtual void onMouseButtonUp(const MouseButton button, const Point2i& position) override;
            virtual void onMouseMove(const Point2i& position) override;

            virtual void onKey(const int keyCode, const char keyChar) override;

        private:
            SceneManager* sceneManager;

            Scene* getCurrentScene() const {
                return sceneManager->getCurrent();
            }
    };
}
