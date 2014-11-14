#include "common/Dumping.hpp"

Dumping::Dumping(const float linear, const float angular):
	linear{linear}, angular{angular} {}

const Dumping Dumping::Zero = Dumping(0.0f, 0.0f);
const Dumping Dumping::One = Dumping(1.0f, 0.0f);
