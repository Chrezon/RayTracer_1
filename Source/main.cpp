// Hello there! This raytracer was made by @Chrezon, the outputs are in PPM format.
// Inspired by "https://raytracing.github.io/books/RayTracingInOneWeekend.html"
#include <iostream>
#include "vector3.h"
#include "ray.h"

static const Vector3 origin(0,0,0);

// This is just a little Hello World!
void rendererTest(int width, int height) {
    // TODO: Add some sort of progress bar tool
    // Header for the PPM file
    std::cout << "P3" << std::endl;
    std::cout << width << " " << height << std::endl;
    std::cout << "256" << std::endl;
    // Body of the PPM file
    for (int i = height-1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            // First have everything in a 0 - 1 range
            double r = double(j) / (width-1);
            double g = double(i) / (height-1);
            double b = 0.25;
            // Then convert appropriately to int
            printColor(std::cout, Vector3(r, g, b));
        }
    }
}

void renderImage(float aspectRatio, int width /*, Vector3& origin*/) {
    // step 1: determine the shape of the screen
    int height = static_cast<int>(width / aspectRatio);
    // also determine an arbitrary viewport
    float viewHeight = 2; // TODO: Make these editable properties sometime
    float viewWidth = aspectRatio * 2;
    float focalLength = 1.0;
    // step 2: for each pixel, print a colour
        // boiler plate code
    std::cout << "P3" << std::endl;
    std::cout << width << " " << height << std::endl;
    std::cout << "256" << std::endl;
        // printing the colours
    for (int j = height-1; j >= 0; j--) {
        for (int i = 0; i < width; i++) {
            // we find the vector3 representing the pixel in the viewport by taking the ratio
            // from the image size
            float horizontal = (double(i) * viewWidth / (width - 1)) - viewWidth/2; // the ratio between current pixel and total pixel, times the width, plus the leftmost
            float vertical = double(j) * viewHeight/ (height - 1) - viewHeight/2;
            Ray r(origin, Vector3(horizontal, vertical, focalLength));
            printColor(std::cout, r.rayColor());
        }
    }
}

int main() {
    const int imgWidth = 256;
    const int imgHeight = 256;

    //rendererTest(imgWidth, imgHeight);
    renderImage(16.0/9.0, 400);
}