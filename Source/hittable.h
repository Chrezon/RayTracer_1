#ifndef HITTABLE
#define HITTABLE

#include "vector3.h"
#include "ray.h"

class Ray;

// convenient class to pass all the information associated with a hit
struct HitRecord {
    Vector3 point;
    Vector3 normal;
    float t;
    bool outerFace;
    // functions
    inline void setFaceDirectionAndNormal(const Ray& r) {
        outerFace = normal.dot(r.direction) < 0; // are they pointing in the same direction?
        normal = outerFace ? normal : -normal; 
    }
};

// parent class for all hittable objects
class Hittable {
public:
    virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& record) const = 0;
};

#endif