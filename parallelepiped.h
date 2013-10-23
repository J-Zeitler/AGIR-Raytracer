#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H

#include "sceneobject.h"
#include <vector>
#include "triangle.h"

class Parallelepiped : public SceneObject
{
public:
    Parallelepiped(const glm::mat4 &ltw,
                   glm::vec3 v0,
                   glm::vec3 v1,
                   glm::vec3 v2,
                   glm::vec3 v3,
                   glm::vec3 v4,
                   glm::vec3 v5,
                   glm::vec3 v6,
                   glm::vec3 v7,        
                   bool nOut,
                   ColorRGB c);
    
    Intersection* intersects(Ray &r);
    
private:
    
    void _calculateTriangles();
    
    bool normalsOut;
    const static int N_TRIANGLES = 12;
    std::vector<Triangle*> triangles;
    
    glm::vec3
         v6,/*--------*/v7,
//      / .           / |
//     /  .          /  |
      v2,/*-------*/v3,
//    |   .         |   |
//    |   .         |   |
         v4,/*. . . |.*/v5,
//    | .           | /
//    |.            |/
      v0,/*-------*/v1;
};

#endif // PARALLELEPIPED_H
