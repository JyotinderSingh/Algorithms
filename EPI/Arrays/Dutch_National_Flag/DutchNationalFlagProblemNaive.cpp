#include <bits/stdc++.h>
using namespace std;

typedef enum
{
     RED,
     WHITE,
     BLUE
} Color;

void DutchFlagPartition(int pivot_index, vector<int> *A_ptr)
{
     vector<int> &A = *A_ptr;
     int pivot = A[pivot_index];

     // first pass: group elements smaller than the pict
     for (int i = 0; i < A.size(); ++i)
     {
          // Look for smaller element
          for (int j = i + 1; j < A.size(); ++j)
          {
               if (A[j] < pivot)
               {
                    swap(A[i], A[j]);
                    break;
               }
          }
     }

     // second pass: grouping elements larger than the pivot
     for (int i = A.size() - 1; i >= 0 && A[i] >= pivot; --i)
     {
          // Look for a larger element. Stop when we reach an eement less
          //     than the pivot, since first element has moved them to the start of A.
          for (int j = i - 1; j >= 0 && A[j] >= pivot; --j)
          {
               if (A[j] > pivot)
               {
                    swap(A[i], A[j]);
                    break;
               }
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