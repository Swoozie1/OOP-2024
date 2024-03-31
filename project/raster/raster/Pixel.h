#ifndef PIXEL_H
#define PIXEL_H

struct  Pixel
{
    Pixel()
        : pix{ 0,0,0 } {}

    Pixel(unsigned int red, unsigned int green, unsigned int blue)
        : pix{ red,green,blue } {}

    unsigned int pix[3];
};

#endif // !PIXEL_H
