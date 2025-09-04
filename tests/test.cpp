#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "prime.hpp"
#include <vector>
#include <set>

TEST_CASE("isPrimeHalf - Composite numbers", "[prime][composite]") {
    long long modOps = 0;
    
    SECTION("Even composite numbers (except 2)") {
        std::vector<int> evenComposites = {4, 6, 8, 10, 12, 14, 16, 18, 20, 100, 1000};
        for (int n : evenComposites) {
            REQUIRE(isPrimeHalf(n, &modOps) == false);
        }
    }
    
    SECTION("Odd composite numbers") {
        std::vector<int> oddComposites = {9, 15, 21, 25, 27, 33, 35, 39, 49, 55};
        for (int n : oddComposites) {
            REQUIRE(isPrimeHalf(n, &modOps) == false);
        }
    }
    
    SECTION("Perfect squares") {
        std::vector<int> squares = {4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225};
        for (int n : squares) {
            REQUIRE(isPrimeHalf(n, &modOps) == false);
        }
    }
    
    SECTION("Semi-primes (product of two primes)") {
        std::vector<int> semiPrimes = {
            6, 10, 14, 15, 21, 22, 26, 33, 34, 35, 38, 39, 46, 51, 
            55, 57, 58, 62, 65, 69, 77, 85, 91, 95
        };
        for (int n : semiPrimes) {
            REQUIRE(isPrimeHalf(n, &modOps) == false);
        }
    }
    
    SECTION("Numbers with multiple factors") {
        std::vector<int> multiFactor = {
            12, 18, 24, 30, 36, 42, 48, 60, 72, 84, 90, 96
        };
        for (int n : multiFactor) {
            REQUIRE(isPrimeHalf(n, &modOps) == false);
        }
    }
    
    SECTION("Large composite numbers") {
        std::vector<int> largeComposites = {
            100, 200, 500, 1000, 1024, 2025, 4096, 10000
        };
        for (int n : largeComposites) {
            REQUIRE(isPrimeHalf(n, &modOps) == false);
        }
    }
    
    SECTION("Carmichael numbers (special composites)") {
        std::vector<int> carmichael = {
            561, 1105, 1729, 2465, 2821
        };
        for (int n : carmichael) {
            REQUIRE(isPrimeHalf(n, &modOps) == false);
        }
    }
    
    SECTION("Edge case composites") {
        std::vector<int> edgeCases = {
            1, 0, -4, -9, -100
        };
        for (int n : edgeCases) {
            REQUIRE(isPrimeHalf(n, &modOps) == false);
        }
    }
}

TEST_CASE("isPrimeHalf - Mod operation counting for composites", "[prime][composite][performance]") {
    long long modOps = 0;
    
    SECTION("Early termination for even composites") {
        modOps = 0;
        isPrimeHalf(4, &modOps);
        REQUIRE(modOps == 1);
        
        modOps = 0;
        isPrimeHalf(100, &modOps);
        REQUIRE(modOps == 1);
    }
    
    SECTION("Early termination for perfect squares") {
        modOps = 0;
        isPrimeHalf(9, &modOps);
        REQUIRE(modOps == 2);
        
        modOps = 0;
        isPrimeHalf(25, &modOps);
        REQUIRE(modOps == 3);
    }
    
    SECTION("Multiple factors require more checks") {
        modOps = 0;
        isPrimeHalf(15, &modOps);
        REQUIRE(modOps == 2);
        
        modOps = 0;
        isPrimeHalf(35, &modOps);
        REQUIRE(modOps == 4);
    }
}

TEST_CASE("isPrimeHalf - Composite number patterns", "[prime][composite][patterns]") {
    long long modOps = 0;
    
    SECTION("All numbers divisible by small primes") {
        std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23};
        std::set<int> testedNumbers;
        
        for (int prime : primes) {
            for (int multiple = 2; multiple <= 10; ++multiple) {
                int n = prime * multiple;
                if (n != prime && testedNumbers.find(n) == testedNumbers.end()) {
                    testedNumbers.insert(n);
                    INFO("Testing " << n << " = " << prime << " × " << multiple);
                    REQUIRE(isPrimeHalf(n, &modOps) == false);
                }
            }
        }
    }
    
    SECTION("Range of composite numbers") {
        std::set<int> testedNumbers;
        
        // Even composites in range
        for (int n = 4; n <= 50; n += 2) {
            if (testedNumbers.find(n) == testedNumbers.end()) {
                testedNumbers.insert(n);
                REQUIRE(isPrimeHalf(n, &modOps) == false);
            }
        }
        
        // Specific odd composites
        std::vector<int> oddComposites = {9, 15, 21, 25, 27, 33, 35, 39, 45, 49};
        for (int n : oddComposites) {
            if (testedNumbers.find(n) == testedNumbers.end()) {
                testedNumbers.insert(n);
                REQUIRE(isPrimeHalf(n, &modOps) == false);
            }
        }
    }
}

TEST_CASE("isPrimeHalf - Comprehensive composite verification", "[prime][composite][comprehensive]") {
    long long modOps = 0;
    
    // Create a set of all unique composite numbers to test
    std::set<int> allComposites;
    
    // Add numbers from all categories
    std::vector<std::vector<int>> compositeCategories = {
        // Even composites
        {4, 6, 8, 10, 12, 14, 16, 18, 20, 100, 1000},
        // Odd composites  
        {9, 15, 21, 25, 27, 33, 35, 39, 49, 55},
        // Perfect squares
        {4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225},
        // Semi-primes
        {6, 10, 14, 15, 21, 22, 26, 33, 34, 35, 38, 39, 46, 51, 55, 57, 58, 62, 65, 69, 77, 85, 91, 95},
        // Multi-factor
        {12, 18, 24, 30, 36, 42, 48, 60, 72, 84, 90, 96},
        // Large composites
        {100, 200, 500, 1000, 1024, 2025, 4096, 10000},
        // Carmichael
        {561, 1105, 1729, 2465, 2821},
        // Edge cases
        {1, 0, -4, -9, -100}
    };
    
    // Combine all numbers into a single set (automatically removes duplicates)
    for (const auto& category : compositeCategories) {
        for (int n : category) {
            allComposites.insert(n);
        }
    }
    
    // Test all unique composite numbers
    SECTION("All unique composite numbers return false") {
        for (int n : allComposites) {
            INFO("Testing composite number: " << n);
            REQUIRE(isPrimeHalf(n, &modOps) == false);
        }
    }
    
    // Verify we have a good number of test cases
    SECTION("Test case count verification") {
        REQUIRE(allComposites.size() > 50); // Should have plenty of test cases
        INFO("Testing " << allComposites.size() << " unique composite numbers");
    }
}

// test for few range of prime numbers if both methods are consistent

// Testing mod operation counts

// test edge cases