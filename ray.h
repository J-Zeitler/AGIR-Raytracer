#ifndef RAY_H
#define RAY_H

#include <glm/glm.hpp>
#include <ostream>

class Ray
{
public:
    Ray();
    Ray(glm::vec3 o, glm::vec3 d, float near = -1, float far = -100);

    glm::vec3 operator() (const float &t);
    
    glm::vec3 origin, dir;
    float tMin, tMax;
    
    friend std::ostream& operator<<(std::ostream &os, const Ray &r);
};

#endif // RAY_H
