// https://www.geeksforgeeks.org/bucket-sort-2/
// We're given a largeset of floating point numbers between 0.0 and 1.0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucketSort(vector<float>& arr){
    
    int n = arr.size();

    // create n empty buckets
    vector<vector<float>> bin(n, vector<float>());

    // put array elements in different buckets
    for(int i = 0; i < n; ++i){
        int b_idx = n * arr[i];    // bucket index
        bin[b_idx].push_back(arr[i]);
    }

    // sort individual buckets
    for(int i = 0; i < n; ++i){
        sort(bin[i].begin(), bin[i].end());
    }

    // concatenate all the buckets into arr
    int index = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < bin[i].size(); ++j){
            arr[index++] = bin[i][j];
        }
    }
}

int main()
{
    vector<float> arr{0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    bucketSort(arr);

    for (auto num : arr)
        cout << num << " ";
    return 0;
}