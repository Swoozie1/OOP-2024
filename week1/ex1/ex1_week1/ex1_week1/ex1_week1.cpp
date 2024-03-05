#include <iostream>
#include <cstring>
#include <cassert>
#include "Perf.h"

const std::size_t MAX_BUFFER_SIZE = 256;


int main()
{
    std::size_t size;

    std::cout << "Enter number of performances: ";
    std::cin >> size;
    std::cin.ignore();

    Performance* performances = new (std::nothrow) Performance[size];
    if (!performances)
    {
        std::cout << "Memory problem!" << std::endl;
        return 1;
    }

    char singerBuffer[MAX_BUFFER_SIZE], discoBuffer[MAX_BUFFER_SIZE];
    int dayOfTheWeek;
    for (std::size_t i = 0; i < size; ++i)
    {
        std::cout << "Enter the name of the singer: ";
        std::cin.getline(singerBuffer, MAX_BUFFER_SIZE);

        std::cout << "Enter the name of the disco: ";
        std::cin.getline(discoBuffer, MAX_BUFFER_SIZE);

        std::cout << "Enter the day of the week (1-7): ";
        std::cin >> dayOfTheWeek;
        std::cin.ignore();

        if (!init(performances[i], singerBuffer, discoBuffer, (WeekDay)(dayOfTheWeek - 1)))
        {
            std::cout << "Problem while initialization" << std::endl;
            deallocate(performances, i);
            return 1;
        }
    }

    sortPerformances(performances, size);
    
    printPerformances(performances, size);

    deallocate(performances, size);

    return 0;
}

