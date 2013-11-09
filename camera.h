#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/constants.hpp>
#include <algorithm>
#include "image.h"
#include "ray.h"
#include "colorrgb.h"
#include "world.h"

class Camera
{
public:
    Camera();
    //Camera(glm::vec3 p, glm::vec3 u, glm::vec3 la, float fx, int w, int h);
    
    void raytrace(World *world);
    void raytraceToFile(World *world, const char *filename);
    
    glm::vec3 position, up, lookAt;
    
    float fovX, fovY;
    
    Image *outputImage;
    
private:
    void _castShadowRays(Intersection *i, World *world);
};

#endif // CAMERA_H
