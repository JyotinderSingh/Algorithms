#include<bits/stdc++.h>
using namespace std;

void EvenOdd(vector<int>* A_ptr) {
    vector<int>& A = *A_ptr;
    int next_even = 0, next_odd = A.size() - 1;
    while(next_even < next_odd){
        if(A[next_even] % 2 == 0) {
            next_even++;
        } else {
            swap(A[next_even], A[next_odd--]);
        }
    }
}

int main(){
    vector<int> arr;
    int n, x;
    cin>>n;
    for(int i = 0; i < n; ++i) {
        cin>>x;
        arr.push_back(x);
    }

    EvenOdd(&arr);

    cout << endl;
    for(int i = 0; i < n; ++i) {
        cout<<arr[i]<<" ";
    }
}
