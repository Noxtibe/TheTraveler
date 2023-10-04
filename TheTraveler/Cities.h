#pragma once
#include <vector>
#include <algorithm>
#include <ctime>

class Cities
{
public :

	int x, y;

	Cities(int x, int y) : x(x), y(y) {};
	double DistanceTo(const Cities& other) const {};


private :

	Cities();


};

