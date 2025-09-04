#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "prime.hpp"
#include <vector>
#include <set>

// Testing few prime identification
TEST_CASE("Prime numbers", "[prime]") {
    long long modOps = 0;
    
    SECTION("Very small primes and edge cases") {
        std::vector<int> primes = {2, 3, 5, 7};
        for (int n : primes) {
            REQUIRE(isPrimeHalf(n, &modOps) == true);
            REQUIRE(isPrimeSqrt(n, &modOps) == true);
        }
    }
    
    SECTION("Medium primes") {
        std::vector<int> primes = {11, 17, 23, 29, 37, 41, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        for (int n : primes) {
            REQUIRE(isPrimeHalf(n, &modOps) == true);
            REQUIRE(isPrimeSqrt(n, &modOps) == true);
        }
    }
    
    SECTION("Larger primes near upper limit") {
        std::vector<int> primes = {
            9901, 9907, 9923, 9929, 9931, 9941, 9949, 9967, 9973, 
        };
        for (int n : primes) {
            REQUIRE(isPrimeHalf(n, &modOps) == true);
            REQUIRE(isPrimeSqrt(n, &modOps) == true);
        }
    }
}

// Testing composite numbers
TEST_CASE("Composite numbers", "[prime][composite]") {
    long long modOps = 0;
    
    SECTION("Even composite numbers (except 2)") {
        std::vector<int> evenComposites = {4, 6, 8, 10, 12, 14, 16, 18, 20, 100, 1000};
        for (int n : evenComposites) {
            REQUIRE(isPrimeHalf(n, &modOps) == false);
            REQUIRE(isPrimeSqrt(n, &modOps) == false);
        }
    }
    
    SECTION("Odd composite numbers") {
        std::vector<int> oddComposites = {9, 15, 21, 25, 27, 33, 35, 39, 49, 55};
        for (int n : oddComposites) {
            REQUIRE(isPrimeHalf(n, &modOps) == false);
            REQUIRE(isPrimeSqrt(n, &modOps) == false);
        }
    }
    
    SECTION("Perfect squares") {
        std::vector<int> squares = {4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225};
        for (int n : squares) {
            REQUIRE(isPrimeHalf(n, &modOps) == false);
            REQUIRE(isPrimeSqrt(n, &modOps) == false);
        }
    }
    
    SECTION("Semi-primes (product of two primes)") {
        std::vector<int> semiPrimes = {
            6, 10, 14, 15, 21, 22, 26, 33, 34, 35, 38, 39, 46, 51, 
            55, 57, 58, 62, 65, 69, 77, 85, 91, 95
        };
        for (int n : semiPrimes) {
            REQUIRE(isPrimeHalf(n, &modOps) == false);
            REQUIRE(isPrimeSqrt(n, &modOps) == false);
        }
    }
    
    SECTION("Numbers with multiple factors") {
        std::vector<int> multiFactor = {
            12, 18, 24, 30, 36, 42, 48, 60, 72, 84, 90, 96
        };
        for (int n : multiFactor) {
            REQUIRE(isPrimeHalf(n, &modOps) == false);
            REQUIRE(isPrimeSqrt(n, &modOps) == false);
        }
    }
    
    SECTION("Large composite numbers") {
        std::vector<int> largeComposites = {
            100, 200, 500, 1000, 1024, 2025, 4096, 10000
        };
        for (int n : largeComposites) {
            REQUIRE(isPrimeHalf(n, &modOps) == false);
            REQUIRE(isPrimeSqrt(n, &modOps) == false);
        }
    }
    
    SECTION("Carmichael numbers (special composites)") {
        std::vector<int> carmichael = {
            561, 1105, 1729, 2465, 2821
        };
        for (int n : carmichael) {
            REQUIRE(isPrimeHalf(n, &modOps) == false);
            REQUIRE(isPrimeSqrt(n, &modOps) == false);
        }
    }
}

// Testing mod operation counts
TEST_CASE("Mod operation counting for composites", "[prime][composite][performance]") {
    long long modOps = 0;
    
    SECTION("Early termination for even composites") {
        modOps = 0;
        isPrimeHalf(4, &modOps);
        REQUIRE(modOps == 1);
        
        modOps = 0;
        isPrimeSqrt(4, &modOps);
        REQUIRE(modOps == 1);
        
        modOps = 0;
        isPrimeHalf(100, &modOps);
        REQUIRE(modOps == 1);

        modOps = 0;
        isPrimeSqrt(100, &modOps);
        REQUIRE(modOps == 1);
    }
    
    SECTION("Early termination for perfect squares") {
        modOps = 0;
        isPrimeHalf(9, &modOps);
        REQUIRE(modOps == 2);
        
        modOps = 0;
        isPrimeSqrt(9, &modOps);
        REQUIRE(modOps == 2);
        
        modOps = 0;
        isPrimeHalf(25, &modOps);
        REQUIRE(modOps == 3);

        modOps = 0;
        isPrimeSqrt(25, &modOps);
        REQUIRE(modOps == 3);
    }
    
    SECTION("Multiple factors require more checks") {
        modOps = 0;
        isPrimeHalf(15, &modOps);
        REQUIRE(modOps == 2);
        
        modOps = 0;
        isPrimeSqrt(15, &modOps);
        REQUIRE(modOps == 2);
        
        modOps = 0;
        isPrimeHalf(35, &modOps);
        REQUIRE(modOps == 3);

        modOps = 0;
        isPrimeSqrt(35, &modOps);
        REQUIRE(modOps == 3);
    }
}

// Test edge cases
TEST_CASE("Edge cases", "[prime][edge]") {
    long long modOps = 0;
    
    SECTION("Negative numbers") {
        std::vector<int> negatives = {-1, -2, -3, -10, -100};
        for (int n : negatives) {
            REQUIRE(isPrimeHalf(n, &modOps) == false);
            REQUIRE(isPrimeSqrt(n, &modOps) == false);
        }
    }
    
    SECTION("Zero and one") {
        REQUIRE(isPrimeHalf(0, &modOps) == false);
        REQUIRE(isPrimeSqrt(0, &modOps) == false);
        REQUIRE(isPrimeHalf(1, &modOps) == false);
        REQUIRE(isPrimeSqrt(1, &modOps) == false);
    }
    
    SECTION("Two (the only even prime)") {
        REQUIRE(isPrimeHalf(2, &modOps) == true);
        REQUIRE(isPrimeSqrt(2, &modOps) == true);
    }
}