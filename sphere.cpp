#include "sphere.h"

Sphere::Sphere(const glm::mat4 &ltw, const float &r) : SceneObject(ltw) {
    radius = r;
    radiusSq = r * r;
}

Sphere::~Sphere() {}

bool Sphere::intersects(const Ray &r) {
    
    
    
    return false;
}


