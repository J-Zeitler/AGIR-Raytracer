#include <iostream>

#include <glm/glm.hpp>
//#include <glm/ext.hpp>
//#include <glm/gtx/constants.hpp>

#include "colorrgb.h"
#include "image.h"
#include "ray.h"
#include "boundingbox.h"

using namespace std;

int main()
{
    int imgWidth = 800;
    int imgHeight = 400;

    Image image = Image(imgWidth, imgHeight);
    ColorRGB color = ColorRGB();

    for( int y = 0;  y < imgHeight; ++y ) {
        for( int x = 0; x < imgWidth; ++x ) {
            color.r = x / ((float) imgWidth);
            color.g = y / ((float) imgHeight);
            color.b = abs(sin(y / 20)) * abs(cos(x / 17));
            image.setPixel(x, y, &color);
        }
    }

    image.saveToPPM("./test.ppm");    

    return 0;
}
