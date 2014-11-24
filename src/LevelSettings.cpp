#include "LevelSettings.hpp"

const LevelSettings LevelSettings::initial = LevelSettings();

LevelSettings::LevelSettings():
	difficulty{LevelDifficulty::Easy}, numAsteroids{4} {}

LevelSettings::LevelSettings(const LevelDifficulty difficulty, const int numAsteroids):
	difficulty{difficulty}, numAsteroids{numAsteroids} {}
