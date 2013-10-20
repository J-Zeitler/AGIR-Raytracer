#include "sphere.h"

Sphere::Sphere(const glm::mat4 &ltw, ColorRGB c, const float &r) : SceneObject(ltw, c) {
    radius = r;
    radiusSq = r * r;
}

Sphere::~Sphere() {}

Intersection* Sphere::intersects(Ray &r) {
    
    glm::vec3 L = this->position - r.origin;
    
    float tca = glm::dot(L, r.dir);
    if(tca < 0) return NULL; //object behind camera
    
    float d2 = glm::dot(L, L) - tca * tca;
    if(d2 > this->radiusSq) return NULL; //ray overshoot
    
    float thc = sqrt(this->radiusSq - d2);
    
    float t0 = tca - thc;
//    float t1 = tca + thc;
    
    if(-t0 < r.tMax) return NULL; //another object in front
    r.tMax = -t0;
    glm::vec3 ip = r(t0);
    return new Intersection(ip, glm::normalize(ip - this->position), this->color);
}
