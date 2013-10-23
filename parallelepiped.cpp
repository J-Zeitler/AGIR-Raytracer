
#include "parallelepiped.h"

Parallelepiped::Parallelepiped(
        const glm::mat4 &ltw,
        glm::vec3 v0, 
        glm::vec3 v1, 
        glm::vec3 v2, 
        glm::vec3 v3, 
        glm::vec3 v4, 
        glm::vec3 v5, 
        glm::vec3 v6, 
        glm::vec3 v7,
        bool nOut,
        ColorRGB c) : SceneObject(ltw, c) {
    
    this->v0 = v0;
    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
    this->v4 = v4;
    this->v5 = v5;
    this->v6 = v6;
    this->v7 = v7;
    normalsOut = nOut;
    
    _calculateTriangles();
}

void Parallelepiped::_calculateTriangles() {
    //front
    triangles.push_back(new Triangle(localToWorld, v0, v1, v2, color));
    triangles.push_back(new Triangle(localToWorld, v1, v3, v2, color));
    
    //bottom
    triangles.push_back(new Triangle(localToWorld, v0, v4, v1, color));
    triangles.push_back(new Triangle(localToWorld, v1, v4, v5, color));
    
    //left
    triangles.push_back(new Triangle(localToWorld, v0, v2, v4, color));
    triangles.push_back(new Triangle(localToWorld, v2, v6, v4, color));
    
    //right
    triangles.push_back(new Triangle(localToWorld, v1, v5, v3, color));
    triangles.push_back(new Triangle(localToWorld, v3, v5, v7, color));
    
    //top
    triangles.push_back(new Triangle(localToWorld, v2, v3, v6, color));
    triangles.push_back(new Triangle(localToWorld, v3, v7, v6, color));
    
    //back
    triangles.push_back(new Triangle(localToWorld, v4, v6, v5, color));
    triangles.push_back(new Triangle(localToWorld, v5, v6, v7, color));
}

Intersection *Parallelepiped::intersects(Ray &r) {
    Intersection *i = NULL, *tmp;
    
    for(int t = 0; t < N_TRIANGLES; ++t) {
        if( tmp = triangles.at(t)->intersects(r) ) {
            i = tmp;
        }
    }
    return i;
}


