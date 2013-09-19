#include "ray.h"

Ray::Ray() {}

Ray::Ray(glm::vec3 o, glm::vec3 d, float near, float far) {
    origin = o; dir = d; tMin = near; tMax = far;
}


float Ray::getTMax() const {
    return tMax;
}

void Ray::setTMax(float value) {
    tMax = value;
}

float Ray::getTMin() const {
    return tMin;
}

void Ray::setTMin(float value) {
    tMin = value;
}

glm::vec3 Ray::getDir() const {
    return dir;
}

void Ray::setDir(const glm::vec3 &value) {
    dir = value;
}

glm::vec3 Ray::getOrigin() const {
    return origin;
}

void Ray::setOrigin(const glm::vec3 &value) {
    origin = value;
}

glm::vec3 Ray::operator ()(const float &t) {
    return origin + dir * t;
}
