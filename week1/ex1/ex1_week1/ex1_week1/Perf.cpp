#pragma once
#include "Perf.h"
#include <iostream>
#include <cstring>
#include <cassert>
#pragma warning(disable:4996)

bool init(Performance& performance, const char* singer, const char* disco, WeekDay weekDay)
{
    performance.singer = new (std::nothrow) char[strlen(singer) + 1];
    if (!performance.singer)
    {
        return false;
    }
    strcpy(performance.singer, singer);

    performance.disco = new (std::nothrow) char[strlen(disco) + 1];
    if (!performance.disco)
    {
        delete[] performance.singer;
        return false;
    }
    strcpy(performance.disco, disco);

    if (weekDay <= WeekDay::UNKNOWN || weekDay >= WeekDay::COUNTER)
    {
        delete[] performance.singer;
        delete[] performance.disco;
        return false;
    }
    performance.weekDay = weekDay;

    return true;
}

void deallocate(Performance* performances, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        delete[] performances[i].singer;
        delete[] performances[i].disco;
    }
    delete[] performances;
}

void printWeekDay(WeekDay weekDay)
{
    assert(weekDay != WeekDay::UNKNOWN && weekDay != WeekDay::COUNTER);

    switch (weekDay)
    {
    case WeekDay::MONDAY:
        std::cout << "Monday";
        return;
    case WeekDay::TUESDAY:
        std::cout << "Tuesday";
        return;
    case WeekDay::WEDNESDAY:
        std::cout << "Wednesday";
        return;
    case WeekDay::THURSDAY:
        std::cout << "Thursday";
        return;
    case WeekDay::FRIDAY:
        std::cout << "Friday";
        return;
    case WeekDay::SATURDAY:
        std::cout << "Saturday";
        return;
    case WeekDay::SUNDAY:
        std::cout << "Sunday";
        return;
    }
}

void printPerformance(const Performance& performance)
{
    assert(performance.singer);
    assert(performance.disco);

    std::cout << performance.singer << " " << performance.disco << " ";
    printWeekDay(performance.weekDay);
}

void printPerformances(const Performance* performances, std::size_t size)
{
    assert(performances);
    assert(size);

    for (std::size_t i = 0; i < size; ++i)
    {
        printPerformance(performances[i]);
        std::cout << std::endl;
    }
}

std::size_t minFrom(Performance* performances, std::size_t from, std::size_t to)
{
    std::size_t min = from;
    for (std::size_t i = from + 1; i < to; ++i)
    {
        if (performances[i].weekDay < performances[min].weekDay)
        {
            min = i;
        }
    }

    return min;
}

void sortPerformances(Performance* performances, std::size_t size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        std::size_t min = minFrom(performances, i, size);
        std::swap(performances[i], performances[min]);
    }
}