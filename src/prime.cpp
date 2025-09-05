#include "prime.hpp"
#include <cmath>

bool isPrimeHalf(int n, long long* modOps) {
    // base cases; no mod operations
    if (n <= 1) {
        return false;
    } else if (n == 2) {
        return true;
    }

    // check for even numbers
    if (n % 2 == 0) {
        if (modOps != nullptr) 
            (*modOps) += 1;
        return false;
    } else {
        if (modOps != nullptr) 
            (*modOps) += 1;
    }
        
    // check for odd numbers
    for (int i = 3; i <= n/2; i += 2) {
        if (modOps != nullptr) {
            (*modOps) += 1;
        }
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool isPrimeSqrt(int n, long long* modOps) {
    // base cases; no mod operations
    if (n <= 1) {
        return false;
    } else if (n == 2) {
        return true;
    }

    // check for even numbers
    if (n % 2 == 0) {
        if (modOps != nullptr) 
            (*modOps) += 1;
        return false;
    } else {
        if (modOps != nullptr) 
            (*modOps) += 1;
    }
        
    // check for odd numbers
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (modOps != nullptr) {
            (*modOps) += 1;
        }
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

long long countModOps(PrimeFn isPrime, int lo, int hi) {
    // invalid case
    if (isPrime == nullptr || hi < lo) {
        return 0;
    }
    long long totalOps = 0;
    for (int i = lo; i <= hi; i++) {
        long long ops = 0;
        isPrime(i, &ops);
        totalOps += ops;
    }
    return totalOps;
}