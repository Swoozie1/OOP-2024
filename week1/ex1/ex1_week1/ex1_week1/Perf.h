
#pragma once
#include <iostream>

enum class WeekDay
{
    UNKNOWN = -1,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
    COUNTER
};

struct Performance
{
    char* singer;
    char* disco;
    WeekDay weekDay;
};


bool init(Performance& performance, const char* singer, const char* disco, WeekDay weekDay);

void deallocate(Performance* performances, std::size_t size);

void printWeekDay(WeekDay weekDay);

void printPerformance(const Performance& performance);

void printPerformances(const Performance* performances, std::size_t size);

std::size_t minFrom(Performance* performances, std::size_t from, std::size_t to);

void sortPerformances(Performance* performances, std::size_t size);