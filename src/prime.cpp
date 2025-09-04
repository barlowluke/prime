#include "prime.hpp"
#include <cmath>

bool isPrimeHalf(int n, long long* modOps) {
    if (n == 2) {
        return true;
    }
    for (int i = 3; i <= n/2; i += 2) {
        if (n % i == 0) {
            modOps += 1;
            return false;
        }
    }
    return true;
}

bool isPrimeSqrt(int n, long long* modOps) {
    if (n == 2) {
        return true;
    }
    for (int i = 3; i < std::sqrt(n); i += 2) {
        if (n % i == 0) {
            modOps += 1;
            return false;
        }
    }
    return true;
}

long long countModOps(PrimeFn isPrime, int lo, int hi) {
    long long totalOps = 0;
    for (int i = lo; i <= hi; i++) {
        long long ops = 0;
        isPrime(i, &ops);
        totalOps += ops;
    }
    return totalOps;
}