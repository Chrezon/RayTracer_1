#ifndef RAY
#define RAY

#include "vector3.h"

class Ray {
public:
    // variables
    Vector3 origin;
    Vector3 direction;

    Ray() {}
    Ray(const Vector3& o, const Vector3& d) : origin(o), direction(d) {}
    Vector3 at(float t) {
        return origin + (t * direction);
    }

    Color rayColor() {
        // TODO: return the colour of the first element this ray intersects with
        Vector3 unitDirection = direction.getUnitVector();
        float t = 0.5 * (unitDirection[1] + 1.0); // always in 0 to 1 range;
        return t * Color(1, 1, 1) + (1-t) * Color(1, 0, 0);
    }
};

#endif