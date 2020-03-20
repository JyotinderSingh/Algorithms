#include <bits/stdc++.h>
using namespace std;

vector<int> generatePrimes(int n)
{
    const int size = floor(0.5 * (n - 3)) + 1; //number of odd numbers other than 1 in the given range
    vector<int> primes;
    primes.emplace_back(2);
    // is_prime[i] represents if (2i + 3) is a prime or not.
    // Initially set each to true. Then use sieving to eliminate non primes.
    deque<bool> is_prime(size, true); //we're only storing odd numbers
    for (int i = 0; i < size; i++)
    {
        if (is_prime[i])
        {
            int p = (2 * i) + 3; //i'th odd number after 1
            primes.emplace_back(p);
            // Sieving from p^2 whose value is (4i^2 + 12i + 9). The index in
            // is_prime is (2i^2 + 6i + 3) because is_prime represents 2i + 3.
            //
            // Note that we need to use long for j because p^2 might overflow
            for (long j = ((static_cast<long>(i) * static_cast<long>(i)) * 2) + 6 * i + 3; j < size; j += p)
            {
                is_prime[j] = false;
            }
        }
    }

    return primes;
}

int main()
{
    for (auto i : generatePrimes(30))
    {
        cout << i << " ";
    }
    return 0;
}

// Optimizations in the code
// Firstly, it only stores odd numbers only starting from 3,
// because we know that even numbers are not prime (except 2).

// Secondly, for the number p, it only starts to sieve from p².
// This is correct because if n<p then n*p was already sieved when multiplications of n were sieved.