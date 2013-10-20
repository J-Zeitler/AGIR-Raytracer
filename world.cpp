#include "world.h"

World::World() {
    pointLights = new std::vector<PointLight*>();
    sceneObjects = new std::vector<SceneObject*>();
    ambientColor = ColorRGB(0.5, 0.5, 0.5);
    backgroundColor = ColorRGB(0.1, 0.1, 0.1);
    backgroundEnabled = true;
}

void World::addSceneObject(SceneObject *so) {
    sceneObjects->push_back(so);
}

void World::addPointLight(PointLight *pl) {
    pointLights->push_back(pl);
}
