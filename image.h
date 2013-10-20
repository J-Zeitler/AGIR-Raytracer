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

    void setPixel(int &x, int &y, ColorRGB *pixelValues);
    void saveToPPM(const char *filename);

    int getWidth() const;
    void setWidth(int value);
    
    int getHeight() const;
    void setHeight(int value);
    
private:
    float *imageData;
    int width, height;
};

#endif // IMAGE_H
