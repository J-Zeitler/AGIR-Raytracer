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

using namespace std;

int main()
{    
    World *world = new World();
    Camera *cam = new Camera();
        
    cam->raytraceToFile(world, "./test.ppm");

    return 0;
}
