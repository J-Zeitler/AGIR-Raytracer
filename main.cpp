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
#include "triangle.h"
#include "parallelepiped.h"
#include "cornellbox.h"

using namespace std;

int main()
{    
    World *world = new World();
    SceneObject *so;
    
//     so = new Sphere(glm::translate<float>(4.0, 0.0, -45.0), ColorRGB(1.0, 1.0, 1.0), 1.0);
//     world->addSceneObject(so);
    
    //some nice spheres
    so = new Sphere(glm::translate<float>(6.0, -7.0, -50.0), ColorRGB(1.0, 1.0, 1.0), 3.0);
    world->addSceneObject(so);
    
    glm::mat4 model =
        glm::translate<float>(-4.0, -10.0, -55.0) *
        glm::rotate<float>(40, glm::vec3(0, 1, 0)) *
        glm::scale<float>(10, 12, 8);
    
    so = new Parallelepiped(
        model,
        glm::vec3(0, 0, 0),
        glm::vec3(1, 0, 0),
        glm::vec3(0, 1, 0),
        glm::vec3(1, 1, 0),
        glm::vec3(0, 0, -1),
        glm::vec3(1, 0, -1),
        glm::vec3(0, 1, -1),
        glm::vec3(1, 1, -1),
        true,
        ColorRGB(1.0, 1.0, 0.0));
    world->addSceneObject(so);
    
//     so = new Parallelepiped(
//         glm::translate<float>(3.0, 0.0, -45.0),
//         glm::vec3(0, 0, 0),
//         glm::vec3(1, 0, 0),
//         glm::vec3(0, 1, 0),
//         glm::vec3(1, 1, 0),
//         glm::vec3(0, 0, -1),
//         glm::vec3(1, 0, -1),
//         glm::vec3(0, 1, -1),
//         glm::vec3(1, 1, -1),
//         true,
//         ColorRGB(1.0, 1.0, 1.0));
//     world->addSceneObject(so);
    
    so = new CornellBox();
    world->addSceneObject(so);
    
        
    world->addPointLight(new PointLight(glm::vec3(0, 6, -40), ColorRGB(0, 0, 0.5)));
    world->addPointLight(new PointLight(glm::vec3(-5, -6, -44), ColorRGB(0.5, 0, 0)));
    world->addPointLight(new PointLight(glm::vec3(4, -6, -40), ColorRGB(0, 0.5, 0)));
    
    Camera *cam = new Camera();
        
    cam->raytraceToFile(world, "./test.ppm");

    std::cout << "Done" << std::endl;
    return 0;
}
