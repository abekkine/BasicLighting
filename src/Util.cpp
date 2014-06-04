#include <stdlib.h>

#include "Util.h"

namespace Util {

	// Generate a random number between min and max values.
	float randomInRange(float min, float max) {

		float value;

		value = min + drand48() * (max-min);

		return value;
	}
}