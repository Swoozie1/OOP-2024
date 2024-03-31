#ifndef IMAGE_H
#define IMAGE_H
#include <vector>
#include <fstream>
#include <iostream>
#include "Pixel.h"
class Image {
public:
    Image()
        : format(""), width(0), height(0), max_pixel_value(255) { }

    void setDim(std::ifstream& myFile);
    void getDim() const ;
    void print() const;
    void grayscale();
    void saveImage();
    void monochrome();
private:
    std::vector<Pixel> pixels;
    char format[2];
    unsigned int width;
    unsigned int height;
    unsigned int max_pixel_value;
};

#endif // !IMAGE_H
