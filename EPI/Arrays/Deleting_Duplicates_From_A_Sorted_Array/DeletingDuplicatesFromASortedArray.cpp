#include <bits/stdc++.h>
using namespace std;

// Returns the number of valid entries after deletion
int DeleteDuplicates(vector<int> *A_ptr)
{
    vector<int> &A = *A_ptr;
    if (A.empty())
    {
        return 0;
    }

    int write_index = 1;
    for (int i = 1; i < A.size(); ++i)
    {
        if (A[write_index - 1] != A[i])
        {
            A[write_index++] = A[i];
        }
    }
    return write_index;
}

// Tester Code
int main()
{
    vector<int> A{1, 1, 2, 3, 4, 5, 5, 6, 6, 13, 13, 13, 13, 15, 16, 46, 46};
    DeleteDuplicates(&A);
    for(auto i: A) {
        cout<<i<<" ";
    }
    return 0;
}
