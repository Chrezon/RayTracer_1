#ifndef RAY
#define RAY

#include "vector3.h"
#include <iostream>
#include <cmath>
// Temp
#include "sphere.h"

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

    Color rayColor() {
        // TODO: return the colour of the first element this ray intersects with
        Sphere s{Vector3(0,0,-1), 0.5};
        HitRecord record{};
        bool t = s.hit(*this, 0, 1000, record);
        if (t) {
            //Vector3 normal = at(t) - Vector3(0, 0, -1); // recall that (0,0,1) is the center of the sphere
            //normal = normal.getUnitVector(); // each number is between -1 and 1
            Vector3 normal = 0.5 * (record.normal + Vector3(1, 1, 1)); // each number is between 0 and 1
            // std::cerr << normal[0] << " " << normal[1] << " " << normal[2] << std::endl;;
            return normal;
        }
        Vector3 unitDirection = direction.getUnitVector();
        double t2 = 0.5 * (unitDirection[1] + 1.0); // always in 0 to 1 range;
        return t2 * Color(1, 1, 1) + (1-t) * Color(1, 0, 0);
    }
};

#endif