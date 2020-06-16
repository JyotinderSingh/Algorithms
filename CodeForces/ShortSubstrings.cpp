#include<bits/stdc++.h>
using namespace std;

string func(string b) {
    int n = b.size();
    string res = "";
    res += b[0];
    for(int i = 1; i <= n - 2; ++i){
        res += b[i++];
    }
    res += b[n - 1];
    return res;
}

int main(){
    int n;
    string str;
    cin>>n;
    for(int i = 0; i < n; ++i) {
        cin>>str;
        cout << func(str)<<endl;
    }
}