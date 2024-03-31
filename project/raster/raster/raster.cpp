#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "Session.h"
#pragma warning (disable : 4996)


int main()
{
    std::ifstream myFile("image.ppm");
    if (!myFile.is_open()) {
        std::cerr << "Problem with opening the file" << "\n";
        return -1;
    }
    Image image;
    image.setDim(myFile);
    image.getDim();
    image.print();
    image.saveImage();
    myFile.close();
   
}
