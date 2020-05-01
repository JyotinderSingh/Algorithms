// takes negative numbers as well
#include <bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &arr)
{
    int min_ele = *min_element(arr.begin(), arr.end());
    int max_ele = *max_element(arr.begin(), arr.end());
    int range = max_ele - min_ele + 1;

    vector<int> count(range, 0);
    vector<int> output(arr.size());

    // we simply store the count of the minimum element at the 0th index
    for (auto num : arr)
    {
        ++count[num - min_ele];
    }

    for (int i = 1; i < count.size(); ++i)
    {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < arr.size(); ++i)
    {
        output[count[arr[i] - min_ele] - 1] = arr[i];
        --count[arr[i] - min_ele];
    }

    arr.clear();
    arr = output;
}

int main()
{
    vector<int> arr{1, 3, -10, 6, 54, 65, 4, 11, -34, -8};
    count_sort(arr);
    for (auto num : arr)
    {
        cout << num << " ";
    }
    return 0;
}