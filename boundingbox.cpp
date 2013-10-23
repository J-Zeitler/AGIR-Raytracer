#include "boundingbox.h"

BoundingBox::BoundingBox() {}

BoundingBox::BoundingBox(glm::vec3 &vmin, glm::vec3 &vmax) {
    min = vmin; max = vmax;
    origin = 0.5f * min + 0.5f * max;
}

glm::vec3 BoundingBox::getOrigin() const {
    return origin;
}

void BoundingBox::setOrigin(const glm::vec3 &value) {
    origin = value;
}

glm::vec3 BoundingBox::getMax() const {
    return max;
}

void BoundingBox::setMax(const glm::vec3 &value) {
    max = value;
}

glm::vec3 BoundingBox::getMin() const {
    return min;
}

void BoundingBox::setMin(const glm::vec3 &value) {
    min = value;
}

bool BoundingBox::containsPoint(glm::vec3 &p) {
    return (min.x <= p.x && 
            min.y <= p.y && 
            min.z <= p.z &&
            max.x >= p.x &&
            max.y >= p.y &&
            max.z >= p.z );
}

bool BoundingBox::intersects(Ray r) {

//     T tmin, tmax, tymin, tymax, tzmin, tzmax;
//     
//     tmin = (bounds[r.sign[0]].x - r.orig.x) * r.invdir.x;
//     tmax = (bounds[1-r.sign[0]].x - r.orig.x) * r.invdir.x;
//     
//     tymin = (bounds[r.sign[1]].y - r.orig.y) * r.invdir.y;
//     tymax = (bounds[1-r.sign[1]].y - r.orig.y) * r.invdir.y;
//     if ((tmin > tymax) || (tymin > tmax))
//         return false;
//     if (tymin > tmin)
//         tmin = tymin;
//     if (tymax < tmax)
//         tmax = tymax;
//     
//     tzmin = (bounds[r.sign[2]].z - r.orig.z) * r.invdir.z;
//     tzmax = (bounds[1-r.sign[2]].z - r.orig.z) * r.invdir.z;
//     if ((tmin > tzmax) || (tzmin > tmax))
//         return false;
//     if (tzmin > tmin)
//         tmin = tzmin;
//     if (tzmax < tmax)
//         tmax = tzmax;
//     
//     if (tmin > r.tmin) r.tmin = tmin;
//     if (tmax < r.tmax) r.tmax = tmax;
//     return true;
    
}
