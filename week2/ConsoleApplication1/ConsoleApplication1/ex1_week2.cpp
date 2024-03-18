#include <iostream>
#include <fstream>

int main()
{
    std::ifstream myFile ("ex1_week2.cpp");

    if (!myFile.is_open()) 
    {
        std::cout << "Problem with file opening" << std::endl;
        return -1;
    }


    char ch;
    while (!myFile.eof()) 
    {
        myFile.get(ch);
        std::cout << ch;
    }

    myFile.close();

    return 0;
}
