using PrimeFn = bool(*)(int, long long*);

//Checks for divisibility up to n/2
bool isPrimeHalf(int n, long long* modOps=nullptr);

//Checks for divisibility up to square root of n
bool isPrimeSqrt(int n, long long* modOps=nullptr);

//counts how many modulo operations a given prime function performs over a range of numbers.
long long countModOps(PrimeFn isPrime, int lo, int hi); 