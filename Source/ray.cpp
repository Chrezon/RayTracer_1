#include "ray.h"
#include "constants.h"
#include "hittable.h"
#include "hittableList.h"
#include "sphere.h"

Color Ray::rayColor(const Hittable& item) {
    // TODO: return the colour of the first element this ray intersects with
    // Sphere s{Vector3(0,0,-1), 0.5};
    HitRecord record{};
    bool t = item.hit(*this, 0, infinity, record);
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