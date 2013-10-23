#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <glm/glm.hpp>
#include "ray.h"

/**
 * Axis aligned bounding box
 */
class BoundingBox
{
public:
    BoundingBox();
    BoundingBox(glm::vec3 &vmin, glm::vec3 &vmax);
    
    bool containsPoint(glm::vec3 &p);
    
    glm::vec3 getMin() const;
    void setMin(const glm::vec3 &value);
    
    glm::vec3 getMax() const;
    void setMax(const glm::vec3 &value);
    
    glm::vec3 getOrigin() const;
    void setOrigin(const glm::vec3 &value);
    
    //important to copy ray here!
    bool intersects(Ray r);
    
private:
    glm::vec3 min, max, origin;
    
};

#endif // BOUNDINGBOX_H
