#include "sceneobject.h"

SceneObject::SceneObject(const glm::mat4 &ltw) {
    localToWorld = ltw;
    worldToLocal = glm::inverse(ltw);
    color = ColorRGB(1.0, 0.0, 0.0);
}

glm::mat4 SceneObject::getWorldToLocal() const {
    return worldToLocal;
}

glm::mat4 SceneObject::getLocalToWorld() const {
    return localToWorld;
}

void SceneObject::setLocalToWorld(const glm::mat4 &value) {
    localToWorld = value;
    worldToLocal = glm::inverse(value);
}
