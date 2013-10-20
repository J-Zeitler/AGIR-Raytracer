#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <glm/glm.hpp>
#include "colorrgb.h"

class Intersection
{
public:
    Intersection();
    Intersection(glm::vec3 ip, glm::vec3 sn, ColorRGB c) 
        : intersectionPoint(ip), surfaceNormal(sn), color(c) {};
    
    bool operator<(const Intersection &i) {
        return (this->intersectionPoint.z > i.intersectionPoint.z);
    };
    
    glm::vec3 intersectionPoint, surfaceNormal;
    ColorRGB color;
};

#endif // INTERSECTION_H
