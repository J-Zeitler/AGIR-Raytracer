#include "ray.h"

Ray::Ray() {}

Ray::Ray(glm::vec3 o, glm::vec3 d, float near, float far) {
    origin = o; dir = glm::normalize(d); tMin = near; tMax = far;
    invdir.x = 1 / dir.x;
    invdir.y = 1 / dir.y;
    invdir.z = 1 / dir.z;
    sign[0] = (invdir.x < 0);
    sign[1] = (invdir.y < 0);
    sign[2] = (invdir.z < 0);
}

glm::vec3 Ray::operator ()(const float &t) {
    return origin + dir * t;
}

std::ostream& operator<<(std::ostream &os, const Ray &r) {
    os << "origin: { " << r.origin.x << ", " << r.origin.y << ", " << r.origin.z << " }" <<
          "direction: { " << r.dir.x << ", " << r.dir.y << ", " << r.dir.z << " }" << std::endl;
    return os;
}
