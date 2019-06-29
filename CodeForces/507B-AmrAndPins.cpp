#include<iostream>
#include<cmath>
using namespace std;

int main() {
    double r,x,y,x1,y1;
    cin>>r>>x>>y>>x1>>y1;
    double distance = sqrt(pow((x1-x), 2) + pow((y1-y), 2));
    // int steps = ceil(distance/(2*r));
    cout<<ceil(distance/(2*r));
}