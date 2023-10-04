#include "TSPSolver.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor for the TSPSolver class, takes a vector of cities as input
TSPSolver::TSPSolver(const vector<City>& _cities) : cities(_cities) 
{
    // Initialize the bestDistance to a very high value
    bestDistance = numeric_limits<double>::max();
}

// Recursive function to find the shortest path
void TSPSolver::findShortestPath(Path currentPath, double currentDistance) 
{
    // If all cities have been visited, update the best path if necessary
    if (currentPath.getCityList().size() == cities.size()) 
    {
        currentDistance += currentPath.getTotalDistance();
        if (currentDistance < bestDistance) 
        {
            bestDistance = currentDistance;
            bestPath = currentPath;
        }
        return;
    }

    // Create a list of remaining unvisited cities
    vector<int> remainingCities;
    for (size_t i = 0; i < cities.size(); i++) 
    {
        if (!currentPath.containsCity(cities[i])) 
        {
            remainingCities.push_back(i);
        }
    }

    // If there are no remaining cities to visit, return
    if (remainingCities.empty()) 
    {
        return;
    }

    // Randomly shuffle the remaining cities to explore different paths
    random_shuffle(remainingCities.begin(), remainingCities.end());

    // Iterate through the remaining cities
    for (size_t i = 0; i < remainingCities.size(); i++) 
    {
        int currentIndex = remainingCities[i];
        const City& currentCity = cities[currentIndex];

        // Create a new path by adding the current city to the current path
        Path newPath = currentPath;
        newPath.addCity(currentCity);
        double newDistance = currentDistance;

        // Calculate the distance between the last added city and the current city
        if (!newPath.getCityList().empty()) {
            const City& lastCity = newPath.getCityList().back();
            double dx = lastCity.getX() - currentCity.getX();
            double dy = lastCity.getY() - currentCity.getY();
            double distance = sqrt(dx * dx + dy * dy);
            newDistance += distance;
        }

        // Recursively explore the new path
        findShortestPath(newPath, newDistance);
    }
}

// Method to start solving the TSP
void TSPSolver::solve() {
    // Seed the random number generator with the current time
    srand(time(0));
    // Choose a random starting city
    int startingCity = rand() % cities.size();

    // Create an initial path with the starting city
    Path initialPath;
    double initialDistance = 0.0;
    initialPath.addCity(cities[startingCity]);

    // Call the recursive function to find the shortest path
    findShortestPath(initialPath, initialDistance);
}

// Method to print the optimal path and its total distance
void TSPSolver::printOptimalPath() const 
{
    const vector<City>& cityList = bestPath.getCityList();
    cout << "Optimal path: ";
    for (size_t i = 0; i < cityList.size(); i++) 
    {
        cout << cityList[i].getName();
        if (i < cityList.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
    cout << "Total distance: " << bestDistance << endl;
}
