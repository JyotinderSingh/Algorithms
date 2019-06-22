#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int pos[100010];
    pos[0] = 0;
    for(int i = 0; i < n; i++)
    {
        int buf;
        cin >> buf;

        pos[i + 1] = pos[i] + buf;
    }

    int m;
    cin>>m;

    for(int i = 0; i < m; i++)
    {
        int worm;
        cin >> worm;

        // you can implement binary search as well, but the STL implementation is obv faster
        int ans = lower_bound(pos, pos + n, worm) - pos;
        cout<<ans<<endl;
    }

    return 0;
}