#ifndef COLORRGB_H
#define COLORRGB_H

class ColorRGB
{
public:
    ColorRGB();
    ColorRGB(float red, float green, float blue);
    
    void setColor(float red, float green, float blue);
    void setColor(ColorRGB c);
    
    ColorRGB operator*(float f);
    ColorRGB operator+(ColorRGB c);
    ColorRGB operator*(ColorRGB c);
    
    float r, g, b;
};

#endif // COLORRGB_H
