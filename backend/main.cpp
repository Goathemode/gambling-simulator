#include "games/plinko/Plinko.h"
#include <iostream>

int main() {
    const int rows = 10;
    const int simulations = 100000;
    
    Plinko plinko(rows);
    plinko.runSimulations(simulations);
    
    std::cout << "Plinko Probability Distribution:\n";
    int bucket = 0;
    for (double prob : plinko.getProbabilities()) {
        std::cout << "Bucket " << bucket++ << ": " << prob * 100 << "%\n";
    }
    
    return 0;
}