#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include <glm/glm.hpp>
#include "colorrgb.h"

class PointLight
{
public:
    PointLight(glm::vec3 p, ColorRGB c = ColorRGB(1, 1, 1));
    
    glm::vec3 position;
    ColorRGB color;
};

#endif // POINTLIGHT_H
