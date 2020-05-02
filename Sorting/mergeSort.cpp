#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1; // first subarray includes element at m
    int n2 = r - m;

    int L[n1], R[n2];

    for(int i = 0; i < n1; ++i){
        L[i] = arr[l + i];
    }
    for(int j = 0; j < n2; ++j){
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k++] = L[i++];
        } else{
            arr[k++] = R[j++];
        }
    }

    while(i < n1){
        arr[k++] = L[i++];
    }

    while(j < n2){
        arr[k++] = R[j++];
    }

}

void mergeSort(vector<int>& arr, int l, int r)
{
    if (l < r)
    {
        int m = l + ((r - l) >> 1);

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    vector<int> arr{3, 34, 245, 25, 79, 69, 4, 22, 27, 65, 44, 89, 9};
    mergeSort(arr, 0, arr.size() - 1);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}