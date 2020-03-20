#include <bits/stdc++.h>
using namespace std;

vector<int> generatePrimes(int n)
{
    vector<int> primes;
    // is_prime[p] repreesents if p is a prime or not. Initially set each to true,
    // except 0 and 1. The use sieving to eliminate nonprimes.
    deque<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p < n; ++p)
    {
        if (is_prime[p])
        {
            primes.emplace_back(p);
            // Sieve p's multiples
            for (int j = p; j <= n; j += p)
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