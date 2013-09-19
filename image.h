#ifndef IMAGE_H
#define IMAGE_H

#include "colorrgb.h"
#include <fstream>
#include <cmath>

class Image
{
public:
    Image();
    Image(const int &w, const int &h);

    ~Image();

    void setPixel(const int &x, const int &y, const ColorRGB *pixelValues);
    void saveToPPM(const char *filename);

private:
    float *imageData;
    int width, height;
};

#endif // IMAGE_H
