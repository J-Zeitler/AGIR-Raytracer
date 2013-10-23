#include "colorrgb.h"

//default constructor -> set color to black
ColorRGB::ColorRGB() : r(0), g(0), b(0) {}

ColorRGB::ColorRGB(float red, float green, float blue) {
    r = red; g = green; b = blue;
}

void ColorRGB::setColor(float red, float green, float blue) {
    r = red; g = green; b = blue;
}

void ColorRGB::setColor(ColorRGB c) {
    this->r = c.r;
    this->g = c.g;
    this->b = c.b;
}

ColorRGB ColorRGB::operator*(float f) {
    return ColorRGB(r * f, g * f, b * f);
}

ColorRGB ColorRGB::operator+(ColorRGB &c) {
    return ColorRGB(r + c.r, g + c.g, b + c.b);
}