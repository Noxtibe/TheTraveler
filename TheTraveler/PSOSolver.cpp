#include "PSOSolver.h"
#include <algorithm>
#include <cmath>
#include <limits>
#include <iostream>
#include <numeric>

using namespace std;

// Constructor for PSOSolver class
PSOSolver::PSOSolver(const vector<City>& _cities, int _populationSize, int _maxIterations)
    : cities(_cities), populationSize(_populationSize), maxIterations(_maxIterations)
{
    bestDistance = numeric_limits<double>::max();
    bestPath.resize(cities.size());
    initializePopulation();
}

// Initialize the population with random permutations
void PSOSolver::initializePopulation()
{
    population.clear();
    for (int i = 0; i < populationSize; ++i)
    {
        vector<int> path(cities.size());
        iota(path.begin(), path.end(), 0); // Create an initial permutation
        random_shuffle(path.begin() + 1, path.end()); // Shuffle the path except the first city (starting city)
        population.push_back(path);
    }
}

// Calculate the total distance of a path
double PSOSolver::calculateDistance(const vector<int>& path) const
{
    double distance = 0;
    for (size_t i = 0; i < path.size() - 1; ++i)
    {
        int city1 = path[i];
        int city2 = path[i + 1];
        double dx = cities[city1].getX() - cities[city2].getX();
        double dy = cities[city1].getY() - cities[city2].getY();
        distance += sqrt(dx * dx + dy * dy);
    }
    int lastCity = path.back();
    int firstCity = path.front();
    double dx = cities[lastCity].getX() - cities[firstCity].getX();
    double dy = cities[lastCity].getY() - cities[firstCity].getY();
    distance += sqrt(dx * dx + dy * dy);
    return distance;
}

// Update the population using the PSO algorithm
void PSOSolver::updateSwarm()
{
    for (int iteration = 0; iteration < maxIterations; ++iteration)
    {
        for (int i = 0; i < populationSize; ++i)
        {
            vector<int>& path = population[i];
            vector<int> newPath = path;

            // Perform update operations on the path here
            // You can implement PSO-specific operations to explore and optimize the paths

            double newDistance = calculateDistance(newPath);
            if (newDistance < bestDistance)
            {
                bestDistance = newDistance;
                bestPath = newPath;
            }
        }
    }
}

// Solve the TSP problem using the PSO algorithm
void PSOSolver::solve()
{
    updateSwarm();
}

// Print the optimal TSP path and its total cost
void PSOSolver::printOptimalPath() const
{
    cout << "Optimal path: ";
    for (int cityIndex : bestPath)
    {
        cout << cities[cityIndex].getName() << " ";
    }
    cout << cities[bestPath.front()].getName() << " (total cost = " << bestDistance << ")" << endl;
}