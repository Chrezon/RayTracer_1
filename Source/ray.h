#ifndef RAY
#define RAY

#include "vector3.h"
#include <iostream>
#include <cmath>

class Hittable;

class Ray {
public:
    // variables
    Vector3 origin;
    Vector3 direction;

    Ray() {}
    Ray(const Vector3& o, const Vector3& d) : origin(o), direction(d) {}
    Vector3 at(float t) const {
        return origin + (t * direction);
    }

    Color rayColor(const Hittable& item);
};

#endif