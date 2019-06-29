#include<iostream>
using namespace std;

int main() {
    long n;
    cin>>n;
    long arr[n+1];
    // long sums[n];
    arr[0] = 0;
    for (long i = 1; i < n+1; ++i) {
        cin>>arr[i];
    }
    long total = 0, energy = 0;
    for(long i = 0; i < n; ++i) {
        if(arr[i] < arr[i+1]) {
           if (energy > arr[i+1] - arr[i]) {
               energy -= arr[i+1] - arr[i];
           }
           else
           {
               total += arr[i+1] - arr[i] - energy;
               energy = 0;
           }
           
        }
        else {
            energy += arr[i] - arr[i+1];
        }
    }
    cout<<total;
}