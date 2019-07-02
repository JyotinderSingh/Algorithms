#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; ++p)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    SieveOfEratosthenes(n);
}