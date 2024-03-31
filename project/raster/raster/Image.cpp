#include "Image.h"

void Image::setDim(std::ifstream& myFile) {
    myFile.getline(this->format, 3);
    myFile >> this->width;
    myFile >> this->height;
    myFile >> this->max_pixel_value;
    unsigned int temp[3];
    while (!myFile.eof()) {
        myFile >> temp[0];
        myFile >> temp[1];
        myFile >> temp[2];
        pixels.push_back({ temp[0], temp[1], temp[2] });
    }

}
void Image::getDim() const {
    std::cout << this->format << '\n' << this->width << ' ' << this->height << ' ' << this->max_pixel_value << '\n';
}

void Image::print() const  {
    for (int i = 0; i < this->pixels.size() - 1; i++) {
        std::cout << this->pixels[i].pix[0] << ' ' << this->pixels[i].pix[1] << ' ' << this->pixels[i].pix[2] << '\n';
    }
}

void Image::grayscale() {
    for (int i = 0; i < this->pixels.size(); i++) {
        unsigned short avgBrightness = 0;
        avgBrightness = ((this->pixels[i].pix[0] + this->pixels[i].pix[1] + this->pixels[i].pix[2]) / 3);
        this->pixels[i].pix[0] = avgBrightness;
        this->pixels[i].pix[1] = avgBrightness;
        this->pixels[i].pix[2] = avgBrightness;
    }
}

void Image::saveImage() {
    std::ofstream out("savedFile.ppm");
    out << this->format << '\n';
    out << this->width << ' ' << this->height << '\n';
    out << this->max_pixel_value << '\n';
    for (int i = 0; i < this->pixels.size(); i++) {
        out << this->pixels[i].pix[0] << ' ' << this->pixels[i].pix[1] << ' ' << this->pixels[i].pix[2] << ' ';
    }
   
    
    out.close();
}