#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <glm/glm.hpp>
#include "intersection.h"
#include "ray.h"
#include "colorrgb.h"

class Triangle
{
public:
    Triangle(const glm::mat4 &ltw, glm::vec3 v0, glm::vec3 v1, glm::vec3 v2, ColorRGB c);
    ~Triangle(){};
    
     Intersection* intersects(Ray &r);
    
private:
    void _calculateNormal();
    void _calculateEdges();
    
    ColorRGB color;
    
    glm::vec3 
       v2,
//     *  *
//     *    *
       e2, n, e1,
//     *        *
//     *          *
       v0,/**/e0,/**/v1;
};

#endif // TRIANGLE_H
