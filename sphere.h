#ifndef SPHERE_H
#define SPHERE_H

#include "sceneobject.h"

class Sphere : public SceneObject
{
public:
    Sphere(const glm::mat4 &ltw, const float &r);
    ~Sphere();
    
    bool intersects(const Ray &r);
    
private:
    float radius, radiusSq; 
};

#endif // SPHERE_H
