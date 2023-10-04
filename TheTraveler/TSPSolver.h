#include "City.h"
#include "Path.h"
#include <vector>

class TSPSolver 
{
public:

    TSPSolver(const std::vector<City>& cities);
    void solve();
    void printOptimalPath() const;

private:

    std::vector<City> cities;
    Path bestPath;
    double bestDistance;

    void findShortestPath(Path currentPath, double currentDistance);
};