#include <cmath>
#include "vector3.h"
#include "constants.h"

// Vector3 Utility
Vector3::Vector3() : coord{0, 0, 0} {}
Vector3::Vector3(float a, float b, float c) : coord{a, b, c} {}

// Color specific utility
std::ostream& printColor(std::ostream& s, const Color c, const int samplesPerPixel) {
    float scale = 1.0/samplesPerPixel;
    float r = c[0]*scale;
    float g = c[1]*scale;
    float b = c[2]*scale;

    int ri = static_cast<int>(255.999 * clamp(r,0,0.999));
    int gi = static_cast<int>(255.999 * clamp(g,0,0.999));
    int bi = static_cast<int>(255.999 * clamp(b,0,0.999));
    s << ri << " " << gi << " " << bi << std::endl;
    return s;
}

float Vector3::getSize() {
    return sqrt(getSquaredSize());
}

float Vector3::getSquaredSize() {
    return coord[0] * coord[0] + 
           coord[1] * coord[1] +
           coord[2] * coord[2];
}

Vector3 Vector3::getUnitVector() {
    float size = getSize();
    Vector3 retval = Vector3(coord[0]/size, coord[1]/size, coord[2]/size);
    return retval;
}

Vector3 operator* (const float f, const Vector3& v) {
    return Vector3(f * v[0], f * v[1], f * v[2]);
}
Vector3 operator* (const Vector3& v, const float f) {
    return f * v;
}
Vector3 operator/ (const Vector3& v, const float f) {
    return (1/f) * v;
}
Vector3 operator+ (const Vector3& a, const Vector3& b){
    return Vector3(a[0] + b[0], a[1] + b[1], a[2]+b[2]);
}

Vector3 operator- (const Vector3& a, const Vector3& b){
    return Vector3(a[0] - b[0], a[1] - b[1], a[2]-b[2]);
}