#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }
    //first tree will always fall to the left, so add that 1 to the result
    //and the right hand tip of that tree will be at its x coordinate
    int result = 1, right = v[0].first;

    for (int i = 1; i < n - 1; ++i)
    {
        if(v[i].first - v[i].second > right) {
            result++;
            right = v[i].first;
        }
        else if (v[i].first + v[i].second < v[i+1].first)
        {
            result++;
            right = v[i].first + v[i].second;
        }
        else
        {
            right = v[i].first;
        }       
    }

    //add 1 to the result for the last tree (only if the numbr of trees is greater than 1)
    if(n > 1) {
        result++;
    }

    cout << result << endl;
}