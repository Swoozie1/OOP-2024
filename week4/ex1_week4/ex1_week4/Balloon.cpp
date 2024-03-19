#include "Balloon.hpp"
#include <cstring>
#pragma warning (disable: 4996)

void Balloon::init_(const char* color, unsigned int cost) {
	strcpy(this->color,color);
	this->cost = cost;
}

void Balloon::setCost(unsigned int cost) {
	this->cost = cost;
}

void Balloon::setColor(const char* color) {
	if (color)
		strcpy(this->color, color);
}

unsigned int Balloon::getCost() {
	return this->cost;
}

const char* Balloon::getColor() {
	return this->color;
}

void Balloon::printInfo() {
	std::cout << "the cost is :" << Balloon::getCost() << " and the color is " << Balloon::getColor() << "\n";
}