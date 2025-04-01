#include "Plinko.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Plinko::Plinko(int rows) : rows(rows), buckets(rows + 1, 0) {
    std::srand(std::time(0));  // Seed RNG
}

int Plinko::simulateDrop(int startPosition) {
    int position = startPosition;
    
    for (int i = 0; i < rows; ++i) {
        // Randomly move left (-1) or right (+1)
        position += (std::rand() % 2) * 2 - 1;
        
        // Ensure position stays within bounds
        position = std::max(0, std::min(position, rows));
    }
    
    return position;
}

void Plinko::runSimulations(int numSimulations) {
    buckets.assign(rows + 1, 0);
    
    // Start in the middle position
    int startPosition = rows / 2;
    
    for (int i = 0; i < numSimulations; ++i) {
        int result = simulateDrop(startPosition);
        buckets[result]++;
    }
    
    calculateProbabilities();
}

void Plinko::calculateProbabilities() {
    int total = 0;
    for (int count : buckets) {
        total += count;
    }
    
    probabilities.clear();
    for (int count : buckets) {
        probabilities.push_back(static_cast<double>(count) / total);
    }
}

const std::vector<double>& Plinko::getProbabilities() const {
    return probabilities;
}