#include "prime.hpp"
#include <iostream>

int main() {
    constexpr int LO = 2, HI = 10000;
    
    // Count modulo operations for both algorithms
    long long halfOps = countModOps(isPrimeHalf, LO, HI);
    long long sqrtOps = countModOps(isPrimeSqrt, LO, HI);
    
    // Print the results
    std::cout << "Half method operations: " << halfOps << "\n";
    std::cout << "Square root method operations: " << sqrtOps << "\n";
    
    // Calculate and print the ratio
    double ratio = static_cast<double>(halfOps) / static_cast<double>(sqrtOps);
    std::cout << "Ratio (Half/Sqrt): " << ratio << "\n";
    
    return 0;
}