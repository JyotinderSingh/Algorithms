#include <bits/stdc++.h>
using namespace std;

vector<int> PlusOne(vector<int> A)
{
    // increment the last element of the vector by 1
    ++A.back();

    for (int i = A.size() - 1; i > 0 && A[i] == 10; --i)
    {
        A[i] = 0, ++A[i - 1];
    }

    if (A[0] == 10)
    {
        // Need additional digit as the most significant digit has a
        // carry out
        A[0] = 0;
        A.insert(A.begin(), 1);
    }

    return A;
}

// Tester code
int main()
{
    vector<int> Number{9, 9, 9, 9};
    Number = PlusOne(Number);
    for(auto i: Number) {
        cout<<i<<" ";
    }
}