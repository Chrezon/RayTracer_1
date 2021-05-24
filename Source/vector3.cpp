#include <cmath>
#include "vector3.h"

// Vector3 Utility
Vector3::Vector3() : coord{0, 0, 0} {}
Vector3::Vector3(float a, float b, float c) : coord{a, b, c} {}

// Color specific utility
std::ostream& printColor(std::ostream& s, const Color c) {
    int r = static_cast<int>(255.999 * c[0]);
    int g = static_cast<int>(255.999 * c[1]);
    int b = static_cast<int>(255.999 * c[2]);
    s << r << " " << g << " " << b << std::endl;
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