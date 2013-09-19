#include <iostream>

#include "lib/glm/glm/glm.hpp"
#include "lib/glm/glm/ext.hpp"
#include "lib/glm/glm/gtx/constants.hpp"

#include "colorrgb.h"
#include "image.h"

using namespace std;

int main()
{
    int imgWidth = 800;
    int imgHeight = 400;

    Image image = Image(imgWidth, imgHeight);
    ColorRGB *color = new ColorRGB();

    for( int y = 0;  y < imgHeight; ++y ) {
        for( int x = 0; x < imgWidth; ++x ) {
            color->r = x / ((float) imgWidth);
            color->g = y / ((float) imgHeight);
            color->b = abs(sin(sqrt(x + y)));
            image.setPixel(x, y, color);
        }
    }

    image.saveToPPM("./test.ppm");

    return 0;
}
