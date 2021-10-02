#ifndef CONSTANTS
#define CONSTANTS

#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>

// Common Headers
#include "ray.h"
#include "vector3.h"

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;
const Vector3 origin(0,0,0);

// Utility Functions
inline double degreesToRadians(double degrees) {
    return degrees * pi / 180.0;
}
inline float randomFloat() {
    return rand() / (RAND_MAX + 1.0);
}
inline float randomFloat(double min, double max) {
    return min + (max - min) * randomFloat();
}
inline Vector3 randomUnitVector() {
    Vector3 retval;
    while(true) {
        retval = Vector3(randomFloat(-1, 1), randomFloat(-1, 1), randomFloat(-1, 1));
        if (retval.getSquaredSize() >= 1) continue;
        break;
    }
    return retval.getUnitVector();
}
inline float clamp(float x, float min, float max) {
    if (x < min) return min;
    if (x > max) return max;
    else return x;
}

#endif