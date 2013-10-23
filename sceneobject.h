#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "ray.h"
#include "colorrgb.h"
#include "intersection.h"

class SceneObject
{
public:
    SceneObject(const glm::mat4 &ltw, ColorRGB c);
    ~SceneObject() {}
    
    virtual Intersection* intersects(Ray &r) = 0;
 
    ColorRGB color;
    glm::vec3 position;
    
    glm::mat4 getLocalToWorld() const;
    void setLocalToWorld(const glm::mat4 &value);
    
    glm::mat4 getWorldToLocal() const;
    void setWorldToLocal(const glm::mat4 &value);
    
protected:   
    glm::mat4 localToWorld, worldToLocal;
};

#endif // SCENEOBJECT_H
