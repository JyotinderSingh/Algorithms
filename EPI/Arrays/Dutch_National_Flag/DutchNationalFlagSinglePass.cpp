#include <bits/stdc++.h>
using namespace std;

void DutchFlagPartition(int pivot_index, vector<int> *A_ptr)
{
    vector<int> &A = *A_ptr;
    int pivot = A[pivot_index];

    /**
      * NOTE
      * Keep the followin invariants during partitioning:
      * bottom group: A[0 : smaller - 1]
      * middle group: A[smaller : equal - 1]
      * unclassified: A[equal : larger - 1]
      * top group: A[larger : A.size() - 1] 
      */

    int smaller = 0, equal = 0, larger = A.size();

    //  keep iterating till there are unclassified elements

    while (equal < larger)
    {
        // A[equal] is the incoming unclassified element
        if (A[equal] < pivot)
        {
            swap(A[smaller++], A[equal++]);
        }
        else if (A[equal] == pivot)
        {
            ++equal;
        }
        else
        {
            // NOTE A[equal] > pivot
            // we swap this element with the last element of the unclassified array
            // that's why we use pre decrement
            swap(A[equal], A[--larger]);
        }
    }
}

// Tester Code
int main()
{
    vector<int> A{1, 2, 1, 1, 1, 3, 3, 2, 1, 3, 3, 2, 2, 2, 3, 3, 2, 1, 1, 2, 1, 3, 3, 3, 2, 1, 3, 2, 1, 1};
    DutchFlagPartition(1, &A);
    for (int i = 0; i < A.size(); ++i)
    {
        cout << A[i] << " ";
    }
}
