#ifndef HITTABLE_LIST
#define HITTABLE_LIST

#include "hittable.h"
#include <memory>
#include <vector>

class HittableList : public Hittable {
public:
    HittableList() {}
    HittableList(std::shared_ptr<Hittable> a) { add(a); }
    // Adding things to the list
    void add(std::shared_ptr<Hittable> a) { objects.push_back(a); }
    void clear() { objects.clear(); }

    // Functioality
    virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& record) const override {
        HitRecord temp;
        float minSoFar = tMax;
        bool hitSomething = false;

        for (const std::shared_ptr<Hittable>& obj : objects) {
            if (obj->hit(r, tMin, minSoFar, temp)) {
                hitSomething = true;
                minSoFar = temp.t;
                record = temp;
            }
        }

        return hitSomething;
    }
public:
    std::vector<std::shared_ptr<Hittable> > objects;
};

#endif