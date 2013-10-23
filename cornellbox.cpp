#include "cornellbox.h"

CornellBox::CornellBox() : 
    SceneObject(
        glm::translate<float>(0, 0, -40) *
        glm::scale<float>(20, 20, 20) *
        glm::translate<float>(-0.5, -0.5, 0.5),
        ColorRGB()) {
    _calculateGeometry();
}

void CornellBox::_calculateGeometry() {
    
    v0 = glm::vec3(0, 0, 1);
    v1 = glm::vec3(1, 0, 1);
    v2 = glm::vec3(0, 1, 1);
    v3 = glm::vec3(1, 1, 1);
    v4 = glm::vec3(0, 0, -2);
    v5 = glm::vec3(1, 0, -2);
    v6 = glm::vec3(0, 1, -2);
    v7 = glm::vec3(1, 1, -2);
    
    l0 = glm::vec3(0.4, 0.99, -0.9);
    l1 = glm::vec3(0.6, 0.99, -0.9);
    l2 = glm::vec3(0.4, 0.99, -1.1);
    l3 = glm::vec3(0.6, 0.99, -1.1);
    
    //bottom
    triangles.push_back(new Triangle(localToWorld, v0, v4, v1, ColorRGB(0.5, 0.5, 0.4)));
    triangles.push_back(new Triangle(localToWorld, v1, v4, v5, ColorRGB(0.5, 0.5, 0.4)));
    
    //left
    triangles.push_back(new Triangle(localToWorld, v0, v2, v4, ColorRGB(1.0, 0.0, 0.0)));
    triangles.push_back(new Triangle(localToWorld, v2, v6, v4, ColorRGB(1.0, 0.0, 0.0)));
    
    //right
    triangles.push_back(new Triangle(localToWorld, v1, v5, v3, ColorRGB(0.0, 1.0, 0.0)));
    triangles.push_back(new Triangle(localToWorld, v3, v5, v7, ColorRGB(0.0, 1.0, 0.0)));
    
    //top
    triangles.push_back(new Triangle(localToWorld, v2, v3, v6, ColorRGB(0.5, 0.5, 0.4)));
    triangles.push_back(new Triangle(localToWorld, v3, v7, v6, ColorRGB(0.5, 0.5, 0.4)));
    
    //back
    triangles.push_back(new Triangle(localToWorld, v4, v6, v5, ColorRGB(0.5, 0.5, 0.4)));
    triangles.push_back(new Triangle(localToWorld, v5, v6, v7, ColorRGB(0.5, 0.5, 0.4)));
    
    //light
//     triangles.push_back(new Triangle(localToWorld, l0, l2, l1, ColorRGB(1.0, 1.0, 1.0)));
//     triangles.push_back(new Triangle(localToWorld, l1, l2, l3, ColorRGB(1.0, 1.0, 1.0)));
}

Intersection *CornellBox::intersects(Ray &r) {
    Intersection *i = NULL, *tmp;
    
    for(int t = 0; t < triangles.size(); ++t) {
        if( tmp = triangles.at(t)->intersects(r) ) {
            i = tmp;
        }
    }
    return i;
}