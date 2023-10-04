#pragma once
#include "City.h"
#include "Path.h"
#include <vector>

class PSOSolver
{
public:

    PSOSolver(const std::vector<City>& cities, int populationSize, int maxIterations);
    void solve(); // Solve the TSP problem
    void printOptimalPath() const; // Print the optimal TSP path and its total cost

private:

    int populationSize;
    int maxIterations;
    std::vector<City> cities;
    std::vector<std::vector<int>> population;
    double bestDistance;
    std::vector<int> bestPath;

    double calculateDistance(const std::vector<int>& path) const; // Calculate the total distance of a path
    void initializePopulation(); // Initialize the population with random permutations
    void updateSwarm(); // Update the population using the PSO algorithm
};