#include "colorrgb.h"

//default constructor -> set color to black
ColorRGB::ColorRGB() : r(0), g(0), b(0) {}

ColorRGB::ColorRGB(float red, float green, float blue) {
    r = red; g = green; b = blue;
}
