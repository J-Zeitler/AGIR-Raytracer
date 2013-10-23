#ifndef CORNELLBOX_H
#define CORNELLBOX_H

#include "sceneobject.h"
#include <vector>
#include "triangle.h"

class CornellBox : public SceneObject
{
public:
    CornellBox();
    ~CornellBox();
    
    Intersection* intersects(Ray& r);

private:
    
    void _calculateGeometry();
    
    const static int N_TRIANGLES = 12;
    std::vector<Triangle*> triangles;
    
    glm::vec3
         v6,/*--------*/v7,
/*      / .*/ l2,l3,  /*|
/*     /  .*/l0,l1,  /* |
*/    v2,/*-------*/v3,
//    |   .         |   |
//    |   .         |   |
         v4,/*. . . |.*/v5,
//    | .           | /
//    |.            |/
      v0,/*-------*/v1;
    
};

#endif // CORNELLBOX_H
