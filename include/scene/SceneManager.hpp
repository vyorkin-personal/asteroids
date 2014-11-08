#pragma once

#include "Base.hpp"
#include "scene/Scene.hpp"

class SceneManager {
    public:
        void renderScene();

        Scene* getCurrent() const;
};
