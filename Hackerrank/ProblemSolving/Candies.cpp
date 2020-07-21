#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n; 
    int64_t arr[n];
    for (int64_t i = 0; i < n; ++i) {
        cin>> arr[i];
    }
    vector<int64_t> dp(n, 1);
    for (int64_t i = 1; i < n; ++i) {
        if(arr[i] > arr[i-1]) {
            dp[i] = dp[i-1] +1;
        }
    }
    // for(int64_t i = 0; i < n; ++i) {
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    for (int64_t i = n-2; i >= 0; --i) {
        if(arr[i] > arr[i+1]) {
            if(dp[i+1]+1 > dp[i]) {
                dp[i] = dp[i+1] + 1;
            }
        }
    }
    // for(int64_t i = 0; i < n; ++i) {
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    int64_t total = 0;
    for(int i = 0; i < n; ++i) {
        total += dp[i];
    }
    cout<<total;
}