#include "Balloon.hpp"

int main()
{
    Balloon balloon;
    balloon.init_("green", 3);
    balloon.printInfo();
    balloon.setColor("red");
    balloon.setCost(6);
    balloon.printInfo();
}

