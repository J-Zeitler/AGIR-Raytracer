#ifndef WORLD_H
#define WORLD_H

#include <glm/glm.hpp>
#include <vector>
#include "colorrgb.h"
#include "sceneobject.h"
#include "pointlight.h"

class World
{
public:
    World();
    
    void addSceneObject(SceneObject *so);
    void addPointLight(PointLight *pl);
    
    std::vector<SceneObject*> *sceneObjects;
    std::vector<PointLight*> *pointLights;
    ColorRGB ambientColor, backgroundColor;
    bool backgroundEnabled;
    
};

#endif // WORLD_H
