#ifndef RAY_H
#define RAY_H

#include "lib/glm/glm/glm.hpp"

class Ray
{
public:
    Ray();
    Ray(glm::vec3 o, glm::vec3 d, float near, float far);

    glm::vec3 operator() (const float &t);

    glm::vec3 getOrigin() const;
    void setOrigin(const glm::vec3 &value);
    
    glm::vec3 getDir() const;
    void setDir(const glm::vec3 &value);

    
    float getTMin() const;
    void setTMin(float value);
    
    float getTMax() const;
    void setTMax(float value);
    
private:
    glm::vec3 origin, dir;
    float tMin, tMax;
};

#endif // RAY_H
