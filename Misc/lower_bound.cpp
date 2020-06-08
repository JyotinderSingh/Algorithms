#include<iostream>
#include<vector>
using namespace std;

// returns the smallest element greater than or equal to target
int lower_bound(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int ans = -1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] >= target){
            ans = arr[mid];
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr{1, 3, 3, 6, 6, 8, 9, 55, 56, 56, 9};
    cout<<lower_bound(arr, 7);
}