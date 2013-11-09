#include "camera.h"

Camera::Camera() {
    position = glm::vec3(0, 0, 0);
    up = glm::vec3(0, 1, 0);
    lookAt = glm::vec3(0, 0, -1);
    fovX = glm::quarter_pi<float>();
    fovY = fovX * 600.0 / 800.0;
    outputImage = new Image(800, 600);
}

//Camera::Camera(
//        glm::vec3 p = glm::vec3(0, 0, 0),
//        glm::vec3 u = glm::vec3(0, 1, 0),
//        glm::vec3 la = glm::vec3(0, 0, -1),
//        float fx = glm::quarter_pi<float>(),
//        int w = 800,
//        int h = 600) {
//
//    position = p;
//    up = u;
//    lookAt = la;
//    fovX = fx;
//    fovY = fx * h / (float) w;
//    outputImage = new Image(w, h);
//}

void Camera::_castShadowRays(Intersection *i, World *world) {
    
    int numObjects = world->sceneObjects->size();
    int numLights = world->pointLights->size();
    glm::vec3 lightDir;
    Ray shadowRay;
    PointLight *pl;
    SceneObject *obj;
    float r, intensity;
    ColorRGB ackColor = ColorRGB();
    bool noHit;
    
    for(int l = 0; l < numLights; ++l) {
        pl = world->pointLights->at(l);
        lightDir = pl->position - i->intersectionPoint;
        r = glm::length(lightDir);
        shadowRay = Ray(i->intersectionPoint, lightDir, 0.1, r);
        noHit = true;
        
        for(int o = 0; o < numObjects; ++o) {
            obj = world->sceneObjects->at(o);
            if( obj->intersects(shadowRay) ) {
                ackColor = ackColor + i->color * 0.001;
                noHit = false; break;
            }
        }

        if(noHit) {
			intensity = glm::dot(i->surfaceNormal, shadowRay.dir) * 1 / std::log(0.5*r);
			if(intensity < 0.0) intensity = 0.0;
			ackColor = ackColor + i->color * (pl->color * intensity + world->ambientColor);
        }
    }
    i->color.setColor(ackColor);
}

void Camera::raytrace(World *world) {
    
    int h = outputImage->getHeight();
    int w = outputImage->getWidth();
    float xx, yy;
    float zz = -1.0f;
    ColorRGB *color = new ColorRGB();
    Ray r;
    
    int numObjects = world->sceneObjects->size();
    
    for(int y = 0; y < h; ++y) {
        for(int x = 0; x < w; ++x) {
            //map xx and yy to image plane            
            xx = tan(fovX / 2) * (2 * x - w) / float(w);
            yy = tan(fovY / 2) * (h - 2 * y) / float(h);
            
            //construct ray
            r = Ray(glm::vec3(0), glm::vec3(xx, yy, zz) - glm::vec3(0));
            
            //Somewhere here, a "RayIterator" class would be nice

            //calculate closest intersection
            Intersection *i = NULL;
            for(int o = 0; o < numObjects; ++o) {
                Intersection *tmp;
                SceneObject *obj = world->sceneObjects->at(o);
                tmp = obj->intersects(r);
                if( tmp ) {
                    i = tmp;
                }
            }
            
            //if ray intersected object, calc color
            if(i) {
                _castShadowRays(i, world);
                color->setColor(i->color);
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
