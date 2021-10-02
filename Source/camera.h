#ifndef CAMERA
#define CAMERA

#include "vector3.h"
#include "constants.h"

class Camera {
public:
    Camera() {
        // TODO: Make these editable
        float aspectRatio = 16.0/9.0;
        width = 400;
        height = static_cast<int>(width / aspectRatio);
        
        viewHeight = 2; // TODO: Make these editable properties sometime
        viewWidth = aspectRatio * viewHeight;
        focalLength = -1.0;

        camOrigin = origin;
    }

    Ray getRay(float u, float v) {
        float horizontal = ((double(u)+randomFloat()) * viewWidth / (width - 1)) - viewWidth/2; // the ratio between current pixel and total pixel, times the width, plus the leftmost
        float vertical = ((double(v)+randomFloat()) * viewHeight/ (height - 1)) - viewHeight/2;
        return Ray(origin, Vector3(horizontal, vertical, focalLength));
    }

public:
    Vector3 camOrigin;
    int width;
    int height;
    float viewWidth;
    float viewHeight;
    float focalLength;
};

#endif