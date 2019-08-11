#include <bits/stdc++.h>

using namespace std;

long maximumPeople(vector <long> p, vector <long> x, vector <long> y, vector <long> r,int n,int m) {
    // Return the maximum number of people that will be in a sunny town after removing exactly one cloud.
    long result=0;
    vector<long> k(n);
    for(int i=0;i<n;i++)
        k[i]=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(x[j]<=y[i]+r[i]||x[j]>=y[i]-r[i])
            {   
                k[i]+=1;
                if(k[i]==1)
                   result+=p[j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(k[i]==0)
           result+=p[i];
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<long> p(n);
    for(int p_i = 0; p_i < n; p_i++){
       cin >> p[p_i];
    }
    vector<long> x(n);
    for(int x_i = 0; x_i < n; x_i++){
       cin >> x[x_i];
    }
    int m;
    cin >> m;
    vector<long> y(m);
    for(int y_i = 0; y_i < m; y_i++){
       cin >> y[y_i];
    }
    vector<long> r(m);
    for(int r_i = 0; r_i < m; r_i++){
       cin >> r[r_i];
    }
    long result = maximumPeople(p, x, y, r,n,m);
    cout << result << endl;
    return 0;
}