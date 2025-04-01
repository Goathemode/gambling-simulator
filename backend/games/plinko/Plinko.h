#pragma once
#include <vector>

class Plinko {
public:
    Plinko(int rows = 10);  // Default 10 rows
    
    // Simulates a single ball drop
    int simulateDrop(int startPosition);
    
    // Runs multiple simulations
    void runSimulations(int numSimulations);
    
    // Gets probability distribution
    const std::vector<double>& getProbabilities() const;
    
private:
    int rows;
    std::vector<int> buckets;
    std::vector<double> probabilities;
    
    void calculateProbabilities();
};