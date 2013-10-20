#include "image.h"


//default constructor -> 512 x 512 image
Image::Image(){
    width = 512; height = 512;
    imageData = new float [ width * height * 3 ];
}

Image::Image(const int &w, const int &h) : width(w), height(h) {
    imageData = new float [ w * h * 3 ];
}

Image::~Image() {
    delete [] imageData;
}

void Image::setPixel(int &x, int &y, ColorRGB *pixelValues) {
    imageData[(y * width + x) * 3] = pixelValues->r;
    imageData[(y * width + x) * 3 + 1] = pixelValues->g;
    imageData[(y * width + x) * 3 + 2] = pixelValues->b;
}

void Image::saveToPPM(const char *filename) {
    std::ofstream ofs;
        ofs.open(filename);
        ofs << "P6\n" << width << " " << height << "\n255\n";
        float *pixel = imageData;
        for (int j = 0; j < height; ++j) {
            for (int i = 0; i < width; ++i) {
                unsigned char r = (unsigned char)(std::max(0.f, std::min(255.f, powf(pixel[0], 1/2.2) * 255 + 0.5f)));
                unsigned char g = (unsigned char)(std::max(0.f, std::min(255.f, powf(pixel[1], 1/2.2) * 255 + 0.5f)));
                unsigned char b = (unsigned char)(std::max(0.f, std::min(255.f, powf(pixel[2], 1/2.2) * 255 + 0.5f)));
                ofs << r << g << b;
                pixel += 3;
            }
        }
        ofs.close();
}

int Image::getHeight() const {
    return height;
}

void Image::setHeight(int value) {
    height = value;
}

int Image::getWidth() const {
    return width;
}

void Image::setWidth(int value) {
    width = value;
}
