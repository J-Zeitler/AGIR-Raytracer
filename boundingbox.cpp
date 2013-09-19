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
