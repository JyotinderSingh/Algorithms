// doesn't work with negative numbers

#include <bits/stdc++.h>
using namespace std;

#define RANGE 255

void counting_sort(vector<int> &arr)
{
    vector<int> count(RANGE + 1, 0);
    vector<int> output(arr.size());

    // store count of each character
    for (auto num : arr)
    {
        count[num]++;
    }

    // Change count[i] so that count[i] now contains actual
    // position of this character in output array
    for (int i = 1; i <= RANGE; ++i)
    {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < arr.size(); ++i)
    {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    arr.clear();
    arr = output;
}

int main()
{
    vector<int> arr{9, 2, 34, 23, 33, 3, 5, 66, 2, 1, 50, 67, 67, 58};
    counting_sort(arr);
    for (auto num : arr)
    {
        cout << num << " ";
    }
    return 0;
}