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
    
    float r, g, b;
};

#endif // COLORRGB_H
