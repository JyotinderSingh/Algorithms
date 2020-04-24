
// CPP program to find the minimum number
// of swaps required to sort an array
// of distinct element

#include <bits/stdc++.h>
using namespace std;

// Function to find minimum swaps to
// sort an array
int findMinSwap(int arr[], int n)
{
    // Declare a vector of pair
    int ans = 0;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; ++i)
    {
        vec[i] = {arr[i], i};
    }
    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; ++i)
    {
        if (vec[i].second == i)
        {
            continue;
        }
        else
        {
            swap(vec[i].first, vec[vec[i].second].first);
            swap(vec[i].second, vec[vec[i].second].second);
        }
        if (i != vec[i].second)
        {
            i--;
        }
        ans++;
    }
    return ans;
}

// Driver code
int main()
{
    int arr[] = {1, 5, 4, 3, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findMinSwap(arr, n);

    return 0;
}