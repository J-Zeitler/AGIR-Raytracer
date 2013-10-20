#include "sceneobject.h"

SceneObject::SceneObject(const glm::mat4 &ltw, ColorRGB c) {
    localToWorld = ltw;
    worldToLocal = glm::inverse(ltw);
    color = c;
    
    position = glm::vec3(ltw * glm::vec4(0, 0, 0, 1)); //poor mans swizzling
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
