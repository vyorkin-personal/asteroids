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

        protected:
            virtual void onInitialize() override;
            virtual void onResize(const Size& size) override;
            virtual void onRender() override;
            virtual void onDestroy() override;
            virtual void onShow() override;
            virtual void onHide() override;

            virtual void onMouseEnter() override;
            virtual void onMouseLeave() override;
            virtual void onMouseButtonDown(const MouseButton button, const int x, const int y) override;
            virtual void onMouseButtonUp(const MouseButton button, const int x, const int y) override;
            virtual void onMouseMove(const int x, const int y) override;
            virtual void onMouseWheel(const int wheelNumber, const int direction, const int x, const int y) override;

            virtual void onKeyDown(const int keyCode, const char keyChar) override;
            virtual void onKeyUp(const int keyCode, const char keyChar) override;

            virtual void onJoystick(const unsigned int button, int x, int y, int z) override;

        private:
            SceneManager* sceneManager;

            Scene* getCurrentScene() const {
                return sceneManager->getCurrent();
            }
    };
}
