#include <bits/stdc++.h>
using namespace std;

void ApplyPermutation(vector<int> *perm_ptr, vector<int> *A_ptr)
{
    vector<int> &perm = *perm_ptr, &A = *A_ptr;
    for (int i = 0; i < A.size(); ++i)
    {
        // checking if the element at index i has been moved by checking if perm[i] is negative
        // perm[i] is non negative
        int next = i;
        while (perm[next] >= 0)
        {
            swap(A[i], A[perm[next]]);
            int temp = perm[next];
            // subtract perm.size() from an entry in perm to make it negative,
            // which indicates the corrosponding element has been moved
            perm[next] -= perm.size();
            next = temp;
        }
    }

    for_each(perm.begin(), perm.end(), [&](int &x) { x += perm.size(); });
}

// Tester code
int main()
{
    vector<int> perm{3,0,1,2};
    vector<int> arr{21,32,43,55};
    ApplyPermutation(&perm, &arr);
    for(auto i: arr) {
        cout<<i<<" ";
    }
}