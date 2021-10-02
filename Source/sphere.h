#ifndef SPHERE
#define SPHERE

#include "hittable.h"
#include "vector3.h"

class Ray;

class Sphere : public Hittable {
public:
    Sphere() {} // really shouldn't be using this but aight
    Sphere(Vector3 c, float r) : center(c), radius(r) {}

    // determine if a ray hits the sphere. 
    virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& record) const override;

// Variable Definitions
    Vector3 center;
    float radius;
};

#endif