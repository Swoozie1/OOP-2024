#include <iostream>

const std::size_t MAX_SIZE = 64;

class Balloon {
public:
	void init_(const char* color, unsigned int cost);
	void printInfo();
	void setColor(const char* color);
	void setCost(unsigned int cost);
	const char * getColor();
	unsigned int getCost();

private:
	char color[MAX_SIZE];
	unsigned int cost = 0;
};