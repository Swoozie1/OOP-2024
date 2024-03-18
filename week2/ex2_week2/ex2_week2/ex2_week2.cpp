#include <iostream>
#include <fstream>

int main()
{
    std::ifstream myFile("fileWithLenght1.txt");

    if (!myFile.is_open())
    {
        std::cout << "Problem with file op" << std::endl;
        return 1;
    }

    char ch;
    unsigned len = 0;
    while (myFile.get(ch))
    {
        len++;
    }
    std::cout << len;
    myFile.close();

    return 0;
}
