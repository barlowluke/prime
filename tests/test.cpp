#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "prime.hpp"

// Testing few prime identification
TEST_CASE("isPrimeHalf - Basic prime numbers", "[prime][basic]") {
    long long modOps = 0;

    SECTION("Small primes") {
        REQUIRE(isPrimeHalf(2, &modOps) == true);
        REQUIRE(isPrimeHalf(3, &modOps) == true);
        REQUIRE(isPrimeHalf(5, &modOps) == true);
        REQUIRE(isPrimeHalf(7, &modOps) == true);
        REQUIRE(isPrimeHalf(11, &modOps) == true);
        REQUIRE(isPrimeHalf(13, &modOps) == true);
        REQUIRE(isPrimeHalf(17, &modOps) == true);
        REQUIRE(isPrimeHalf(19, &modOps) == true);
        REQUIRE(isPrimeHalf(23, &modOps) == true);
        REQUIRE(isPrimeHalf(29, &modOps) == true);
    }
}

//Testing composite numbers

// test for few range of prime numbers if both methods are consistent

// Testing mod operation counts

// test edge cases