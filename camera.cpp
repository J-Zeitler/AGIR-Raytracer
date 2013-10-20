#include "camera.h"

Camera::Camera() {
    position = glm::vec3(0, 0, 0);
    up = glm::vec3(0, 1, 0);
    lookAt = glm::vec3(0, 0, -1);
    fovX = glm::quarter_pi<float>();
    fovY = fovX * 600.0 / 800.0;
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
    float xx, yy;
    float zz = -1.0f;
    ColorRGB *color = new ColorRGB();
    Ray r;
    
    int numObjects = world->sceneObjects->size();
//    int numLights = world->pointLights->size();
    
    for(int y = 0; y < h; ++y) {
        for(int x = 0; x < w; ++x) {
            //map xx and yy to image plane            
            xx = tan(fovX / 2) * (2 * x - w) / float(w);
            yy = tan(fovY / 2) * (h - 2 * y) / float(h);
            
            //construct ray
            r = Ray(glm::vec3(0), glm::vec3(xx, yy, zz) - glm::vec3(0));
            
            //calculate closest intersection
            Intersection *i = NULL;
            for(int o = 0; o < numObjects; ++o) {
                Intersection *tmp;
                SceneObject *obj = world->sceneObjects->at(o);
                if( tmp = obj->intersects(r) ) {
                    i = tmp;
                }
            }
            
            if(i) {
                PointLight *pl = world->pointLights->at(0);
                float nDotL = glm::dot(i->surfaceNormal, glm::normalize((pl->position - i->intersectionPoint)));
                if(nDotL < 0.0) nDotL = 0.0;
                color->setColor(i->color * nDotL);
                outputImage->setPixel(x, y, color);
            } else {
                outputImage->setPixel(x, y, &world->backgroundColor);
            }
        }
    }
}

void Camera::raytraceToFile(World *world, const char *filename) {
    raytrace(world);
    outputImage->saveToPPM(filename);
}

