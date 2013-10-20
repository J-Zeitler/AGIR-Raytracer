#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <glm/glm.hpp>
#include "ray.h"
#include "colorrgb.h"

class SceneObject
{
public:
    SceneObject(const glm::mat4 &ltw);
    virtual ~SceneObject() {}
    
    virtual bool intersects(const Ray &r) const = 0;
 
    ColorRGB color;
    
    glm::mat4 getLocalToWorld() const;
    void setLocalToWorld(const glm::mat4 &value);
    
    glm::mat4 getWorldToLocal() const;
    void setWorldToLocal(const glm::mat4 &value);
    
private:   
    glm::mat4 localToWorld, worldToLocal;
};

#endif // SCENEOBJECT_H
