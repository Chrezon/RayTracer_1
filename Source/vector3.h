#ifndef VECTOR3
#define VECTOR3

#include <iostream>

// Base class for vector 3
class Vector3 {
    // operations we need:
    // add, subtract, multiply, divide (scalar+vector)
    // getters and setters
    // dot product, cross product
public:
    // constructors:
    Vector3();
    Vector3(float a, float b, float c);

    // Operator overloads
    float operator[] (const int i) const {return coord[i];}
    Vector3 operator- () const {
        return Vector3(-coord[0], -coord[1], -coord[2]);
    }
    //Vector3& operator+= (const Vector3 other);
    //Vector3& operator-= (const Vector3 other);
    //Vector3& operator*= (const float c);
    //Vector3& operator/= (const float c);
    //void operator<< (std::ostream s);
    float getSize();
    float getSquaredSize();
    Vector3 getUnitVector();

    float dot(const Vector3& other) const {
        return coord[0]*other[0] + coord[1]*other[1] + coord[2]*other[2];
    }
    
    float coord[3]; // coordinates

};

// Vector3 utils
Vector3 operator* (const float f, const Vector3& v);
Vector3 operator* (const Vector3& v, const float f);
Vector3 operator/ (const Vector3& v, const float f);
Vector3 operator+ (const Vector3& a, const Vector3& b);
Vector3 operator- (const Vector3& a, const Vector3& b);

// Aliases to Vector3
using Color = Vector3;

// Color utils
std::ostream& printColor(std::ostream& s, const Color c);

#endif