// Hello there! This raytracer was made by @Chrezon, the outputs are in PPM format.
// Inspired by "https://raytracing.github.io/books/RayTracingInOneWeekend.html"
#include <iostream>

// This is just a little Hello World!
void rendererTest(int width, int height) {
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
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);
            // Finally output
            std::cout << ir << " " << ig << " " << ib << std::endl;
        }
    }
}

int main() {
    const int imgWidth = 256;
    const int imgHeight = 256;

    rendererTest(imgWidth, imgHeight);
}