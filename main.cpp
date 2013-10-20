#include <iostream>

#include <glm/glm.hpp>
//#include <glm/ext.hpp>
//#include <glm/gtx/constants.hpp>

#include "colorrgb.h"
#include "image.h"
#include "ray.h"
#include "boundingbox.h"
#include "camera.h"
#include "world.h"
#include "sphere.h"
#include "pointlight.h"

using namespace std;

int main()
{    
    World *world = new World();
    SceneObject *so;
//    so = new Sphere(glm::translate<float>(1.0, 0.0, -10.0), ColorRGB(1.0, 0.0, 1.0), 2.0);
//    world->addSceneObject(so);
    so = new Sphere(glm::translate<float>(0.0, 0.0, -40.0), ColorRGB(1.0, 0.0, 0.0), 2.0);
    world->addSceneObject(so);
    so = new Sphere(glm::translate<float>(4.0, 4.0, -50.0), ColorRGB(0.0, 1.0, 0.0), 2.0);
    world->addSceneObject(so);
    so = new Sphere(glm::translate<float>(6.0, -6.0, -30.0), ColorRGB(0.0, 0.0, 1.0), 2.0);
    world->addSceneObject(so);
    so = new Sphere(glm::translate<float>(-8.0, 8.0, -45.0), ColorRGB(1.0, 1.0, 0.0), 2.0);
    world->addSceneObject(so);
    so = new Sphere(glm::translate<float>(-3.0, -3.0, -20.0), ColorRGB(0.0, 1.0, 1.0), 2.0);
    world->addSceneObject(so);
    
    world->addPointLight(new PointLight());
    
    Camera *cam = new Camera();
        
    cam->raytraceToFile(world, "./test.ppm");

    return 0;
}
