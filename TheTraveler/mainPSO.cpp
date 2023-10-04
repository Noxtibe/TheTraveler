#include <iostream>
#include <vector>
#include "City.h"
#include "Path.h"
#include "PSOSolver.h"
#include "TSPSolver.h"

using namespace std;

int main() 
{
    // Create a list of cities with their names and coordinates
    vector<City> cities = 
    {
        City('A', 0.0, 0.0),
        City('B', 1.0, 0.0),
        City('C', 1.0, 1.0),
        City('D', 0.0, 1.0),
        City('E', 2.0, 0.5)
    };

    // Set the population size and maximum iterations for the PSO algorithm
    int populationSize = 100;
    int maxIterations = 1000;

    // Create a TSPSolver instance with the list of cities, population size, and maximum iterations
    PSOSolver solver(cities, populationSize, maxIterations);

    // Solve the TSP problem using the PSO algorithm
    solver.solve();

    // Print the optimal TSP path and its total cost
    solver.printOptimalPath();

    return 0;
}

// PSO (Particle Swarm Optimization) is a heuristic optimization algorithm used in this solver.
// It explores the solution space by iteratively updating the population of potential solutions
// (represented by permutations of cities) to find the optimal solution to the Traveling Salesman Problem (TSP).
// PSO mimics the behavior of a swarm of particles searching for the best path, and it continuously
// refines the paths based on local and global best solutions found during the search.


// I just recopied this text from internet
// I found this type of algorithm with some research and it has tickle my curiosity
// So i decided to give it a try so it's not really from me but i've done a lot of
// research about it and i understand it about 80 - 90%, that's why there is a lot of //
