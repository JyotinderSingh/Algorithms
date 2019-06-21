#include<iostream>
using namespace std;

long long fib(long long n){
 long long first = 0, second = 1, third;

 for(long long i = 2; i<=n; ++i){
     third = (second +first)%10;
     first = second;
     second = third;
 }   
 return third;
 
}

int main(){ 
    long long n;
    cin>>n;
    if(n==1 || n==2) {
        cout<<"1";
        return 0;
    }
    cout<<fib(n);
    return 0;
}