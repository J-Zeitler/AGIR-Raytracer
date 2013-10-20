#include "pointlight.h"

PointLight::PointLight() {
    position = glm::vec3(10, 10, -30);
    color = ColorRGB(1, 1, 1);
}
