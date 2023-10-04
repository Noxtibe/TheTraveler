#include "City.h"
#include "Path.h"
#include "TSPSolver.h"
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    vector<City> cities = 
    {
        City('A', 0.0, 0.0),
        City('B', 1.0, 0.0),
        City('C', 1.0, 1.0),
        City('D', 0.0, 1.0),
        City('E', 2.0, 0.5)
    };

    TSPSolver solver(cities);
    solver.solve();
    solver.printOptimalPath();

    return 0;
}