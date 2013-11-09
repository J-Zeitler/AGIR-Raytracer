#include "triangle.h"
#include <glm/virtrev/xstream.hpp>

Triangle::Triangle(
    const glm::mat4 &ltw,
    glm::vec3 v0,
    glm::vec3 v1,
    glm::vec3 v2,
    ColorRGB c) {
    
    this->v0 = glm::vec3(ltw * glm::vec4(v0, 1));
    this->v1 = glm::vec3(ltw * glm::vec4(v1, 1));
    this->v2 = glm::vec3(ltw * glm::vec4(v2, 1));
    
    color = c;
    
//     std::cout << "v0: (" << this->v0.x << ", " << this->v0.y << ", " << this->v0.z << ") ";
//     std::cout << "v1: (" << this->v1.x << ", " << this->v1.y << ", " << this->v1.z << ") ";
//     std::cout << "v2: (" << this->v2.x << ", " << this->v2.y << ", " << this->v2.z << ") ";
  
    _calculateNormal();
    _calculateEdges();
}

void Triangle::_calculateNormal() { 
    n = glm::normalize(glm::cross((v1-v0), (v2-v0)));
    
//     std::cout << "normal: (" << n.x << ", " << n.y << ", " << n.z << ")" << std::endl;
}

void Triangle::_calculateEdges() {
    e0 = v1 - v0;
    e1 = v2 - v1;
    e2 = v0 - v2;
}

Intersection* Triangle::intersects(Ray &r) {
    
    /*************************************
     * Möller-Trumbore algorithm
     *************************************/
    
    
    
    
    /*************************************
     * Straigt forward geometric solution
     *************************************/
    
    glm::vec3 normal = (glm::dot(n, r.dir) < 0) ? n : (-1.0f * n); //double sided
    
    float den = glm::dot(normal, r.dir);
    if(den < 0.00000001 && den > -0.00000001) return NULL; //triangle-plane || ray
    
    float d = glm::dot(normal, v0);
    float num = - glm::dot(normal, r.origin) + d;
    float t = num / den;
    
    if(t < 0) return NULL; //triangle behind ray
    
    if(t > r.tMax) return NULL; //another object in front
    
    glm::vec3 p = r(t-0.0001); //hit point (adjusted for numerical error)
    
    glm::vec3 c0 = p - v0;
    glm::vec3 c1 = p - v1;
    glm::vec3 c2 = p - v2;
    
    //inside-outside test
    if(normal != n) {
        if( glm::dot(normal, glm::cross(-e0, c0)) > 0 &&
        glm::dot(normal, glm::cross(-e1, c1)) > 0 &&
        glm::dot(normal, glm::cross(-e2, c2)) > 0) {
            r.tMax = t;
            return new Intersection(p, normal, color);
        }
    } else {
       if( glm::dot(n, glm::cross(e0, c0)) > 0 &&
        glm::dot(n, glm::cross(e1, c1)) > 0 &&
        glm::dot(n, glm::cross(e2, c2)) > 0) {
            r.tMax = t;
            return new Intersection(p, n, color);
        }
    }
    
    
    return NULL;
    
    
}
