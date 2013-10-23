#include "pointlight.h"

PointLight::PointLight() {
    position = glm::vec3(0, 7, -40);
    color = ColorRGB(1, 1, 1);
}
