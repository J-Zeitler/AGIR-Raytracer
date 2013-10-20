#include "camera.h"

Camera::Camera() {
    position = glm::vec3(0, 0, 0);
    up = glm::vec3(0, 1, 0);
    lookAt = glm::vec3(0, 0, -1);
    fovX = glm::quarter_pi<float>();
    fovY = fovX * 800 / (float) 600;
    outputImage = new Image(800, 600);
}

Camera::Camera(
        glm::vec3 p = glm::vec3(0, 0, 0),
        glm::vec3 u = glm::vec3(0, 1, 0),
        glm::vec3 la = glm::vec3(0, 0, -1),
        float fx = glm::quarter_pi<float>(),
        int w = 800,
        int h = 600) {
    
    position = p;
    up = u;
    lookAt = la;
    fovX = fx;
    fovY = fx * h / (float) w;
    outputImage = new Image(w, h);
}

void Camera::raytrace(World *world) {
    
    int h = outputImage->getHeight();
    int w = outputImage->getWidth();
    float normX, normY, xx, yy;
    float zz = -1.0f;
    ColorRGB *color = new ColorRGB(0.0f, 0.0f, 0.0f);
    Ray r;
    
    int numObjects = world->sceneObjects->size();
    
    for(int y = 0; y < h; ++y) {
        for(int x = 0; x < w; ++x) {
            
            //normalize x,y → normX, normY € {0, 1}
            normX = (x + 0.5) / (float) w;
            normY = (y + 0.5) / (float) h;
            
            //remap x,y → xx, yy € {-1, 1}
            xx = 2 * normX - 1.0;
            yy = 1.0 - 2 * normY;
            
            //construct ray
            r = Ray(this->position, glm::vec3(xx, yy, zz));
            
            for(int o = 0; o < numObjects; ++o) {
                
            }
            
//            color->setColor((xx + 1) / 2.0, (yy + 1) / 2.0, 0.0f);
            outputImage->setPixel(x, y, &world->backgroundColor);
        }
    }
    
}

void Camera::raytraceToFile(World *world, const char *filename) {
    raytrace(world);
    outputImage->saveToPPM(filename);
}

