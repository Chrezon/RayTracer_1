#include "sphere.h"
#include "ray.h"

bool Sphere::hit(const Ray& r, float tMin, float tMax, HitRecord& record) const {
    Vector3 oc = r.origin - center;
    float a = (r.direction).dot(r.direction);
    float b = (r.direction).dot(oc);
    float c = oc.dot(oc) - radius * radius;
    float disc = b*b - a*c;
    if (disc < 0) return false;
    // return the t-value which intersects (we only want the positive t-values though)
    float root = (-b - sqrt(disc))/a;
    if (root < tMin || root > tMax) return false;
    // Now we know the root is within the desired range, we set the values in record
    record.point = r.at(root);
    record.t = root;
    record.normal = (record.point - center) / radius; // since we want a unit vector
    record.setFaceDirectionAndNormal(r);
    return true;
}