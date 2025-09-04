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
        REQUIRE(modOps == 3);
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

// Helper function to calculate expected modOps based on the rules
long long calculateExpectedModOps(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 0;
    if (n % 2 == 0) return 1; // Even numbers
    
    // Odd numbers: count from 3, add 2 each time
    // For n >= 3, number of modOps = (n - 1) / 2
    return (n - 1) / 2;
}

TEST_CASE("countModOps - Single numbers with specific rules", "[countModOps][single]") {
    SECTION("Numbers <= 1 should have 0 modOps") {
        REQUIRE(countModOps(isPrimeHalf, 0, 0) == 0);
        REQUIRE(countModOps(isPrimeHalf, 1, 1) == 0);
        REQUIRE(countModOps(isPrimeHalf, -5, -5) == 0); // Still test negative but expect 0
    }
    
    SECTION("Number 2 should have 0 modOps") {
        REQUIRE(countModOps(isPrimeHalf, 2, 2) == 0);
    }
    
    SECTION("Even numbers should have 1 modOp") {
        REQUIRE(countModOps(isPrimeHalf, 4, 4) == 1);
        REQUIRE(countModOps(isPrimeHalf, 6, 6) == 1);
        REQUIRE(countModOps(isPrimeHalf, 8, 8) == 1);
        REQUIRE(countModOps(isPrimeHalf, 10, 10) == 1);
        REQUIRE(countModOps(isPrimeHalf, 100, 100) == 1);
    }
    
    SECTION("Odd numbers should follow the pattern") {
        REQUIRE(countModOps(isPrimeHalf, 3, 3) == 1);   // (3-1)/2 = 1
        REQUIRE(countModOps(isPrimeHalf, 5, 5) == 2);   // (5-1)/2 = 2
        REQUIRE(countModOps(isPrimeHalf, 7, 7) == 3);   // (7-1)/2 = 3
        REQUIRE(countModOps(isPrimeHalf, 9, 9) == 4);   // (9-1)/2 = 4
        REQUIRE(countModOps(isPrimeHalf, 11, 11) == 5); // (11-1)/2 = 5
        REQUIRE(countModOps(isPrimeHalf, 15, 15) == 7); // (15-1)/2 = 7
    }
}

TEST_CASE("countModOps - Range verification with rules", "[countModOps][range]") {
    SECTION("Empty range should return 0") {
        REQUIRE(countModOps(isPrimeHalf, 10, 5) == 0);
    }
    
    SECTION("Range with single number") {
        REQUIRE(countModOps(isPrimeHalf, 4, 4) == calculateExpectedModOps(4));
        REQUIRE(countModOps(isPrimeHalf, 7, 7) == calculateExpectedModOps(7));
        REQUIRE(countModOps(isPrimeHalf, 2, 2) == calculateExpectedModOps(2));
    }
    
    SECTION("Small ranges") {
        // Range 1-3: 0 (n=1) + 0 (n=2) + 1 (n=3) = 1
        REQUIRE(countModOps(isPrimeHalf, 1, 3) == 1);
        
        // Range 4-6: 1 (n=4) + 2 (n=5) + 1 (n=6) = 4
        REQUIRE(countModOps(isPrimeHalf, 4, 6) == 4);
        
        // Range 7-9: 3 (n=7) + 1 (n=8) + 4 (n=9) = 8
        REQUIRE(countModOps(isPrimeHalf, 7, 9) == 8);
    }
    
    SECTION("Range with only even numbers") {
        // 4,6,8,10: all have 1 modOp each = 4 total
        REQUIRE(countModOps(isPrimeHalf, 4, 10) == 4);
        
        // 100,102,104: all have 1 modOp each = 3 total
        REQUIRE(countModOps(isPrimeHalf, 100, 104) == 3);
    }
    
    SECTION("Range with only odd numbers") {
        // 3,5,7,9: 1 + 2 + 3 + 4 = 10
        REQUIRE(countModOps(isPrimeHalf, 3, 9) == 10);
        
        // 11,13,15: 5 + 6 + 7 = 18
        REQUIRE(countModOps(isPrimeHalf, 11, 15) == 18);
    }
    
    SECTION("Mixed range") {
        // 2,3,4,5: 0 + 1 + 1 + 2 = 4
        REQUIRE(countModOps(isPrimeHalf, 2, 5) == 4);
        
        // 8,9,10,11: 1 + 4 + 1 + 5 = 11
        REQUIRE(countModOps(isPrimeHalf, 8, 11) == 11);
    }
}

TEST_CASE("countModOps - Additivity property", "[countModOps][additivity]") {
    SECTION("Sum of parts equals whole") {
        long long total = countModOps(isPrimeHalf, 1, 10);
        long long part1 = countModOps(isPrimeHalf, 1, 5);
        long long part2 = countModOps(isPrimeHalf, 6, 10);
        
        REQUIRE(total == part1 + part2);
        
        // Manual calculation: 
        // n=1:0, n=2:0, n=3:1, n=4:1, n=5:2, n=6:1, n=7:3, n=8:1, n=9:4, n=10:1
        // Total = 0+0+1+1+2+1+3+1+4+1 = 14
        REQUIRE(total == 14);
    }
    
    SECTION("Multiple partitions") {
        long long total = countModOps(isPrimeHalf, 3, 9);
        long long part1 = countModOps(isPrimeHalf, 3, 5);
        long long part2 = countModOps(isPrimeHalf, 6, 7);
        long long part3 = countModOps(isPrimeHalf, 8, 9);
        
        REQUIRE(total == part1 + part2 + part3);
    }
}

TEST_CASE("countModOps - Pattern consistency", "[countModOps][pattern]") {
    SECTION("Verify pattern for consecutive numbers") {
        for (int start = 3; start <= 20; start += 2) { // Test odd numbers
            long long expected = calculateExpectedModOps(start);
            long long actual = countModOps(isPrimeHalf, start, start);
            REQUIRE(actual == expected);
        }
        
        for (int start = 4; start <= 20; start += 2) { // Test even numbers
            long long expected = calculateExpectedModOps(start);
            long long actual = countModOps(isPrimeHalf, start, start);
            REQUIRE(actual == expected);
        }
    }
    
    SECTION("Large number verification") {
        // Test a large even number
        REQUIRE(countModOps(isPrimeHalf, 1000, 1000) == 1);
        
        // Test a large odd number
        REQUIRE(countModOps(isPrimeHalf, 1001, 1001) == 500); // (1001-1)/2 = 500
        REQUIRE(countModOps(isPrimeHalf, 999, 999) == 499);   // (999-1)/2 = 499
    }
}