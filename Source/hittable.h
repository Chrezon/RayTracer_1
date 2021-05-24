#ifndef HITTABLE
#define HITTABLE

#include "vector3.h"

class Ray;

// parent class for all hittable objects
struct HitRecord {
    Vector3 point;
    Vector3 normal;
    float t;
};

class Hittable {
public:
    virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& record) const = 0;
};

#endif