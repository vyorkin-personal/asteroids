#pragma once

#include "Base.hpp"

enum LevelDifficulty { Easy, Normal, Hard };

struct LevelSettings {
    LevelSettings();
    LevelSettings(const LevelSettings&) = default;
    LevelSettings(const LevelDifficulty difficulty, const int numAsteroids);

    LevelDifficulty difficulty;
    int numAsteroids;

    static const LevelSettings initial;
};
