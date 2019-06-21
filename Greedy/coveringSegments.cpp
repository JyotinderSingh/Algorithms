#include <bits/stdc++.h>
using namespace std;

struct Segment
{
    int start, end;
};

bool sortFunction(Segment i, Segment j) { return (i.end < j.end); }

vector<int> optimal_points(vector<Segment> &segments)
{

    sort(segments.begin(), segments.end(), sortFunction);

    vector<int> points;
    int point = segments[0].end;
    points.push_back(point);

    for (int i = 1; i < segments.size(); ++i)
    {
        if (point < segments[i].start || point > segments[i].end)
        {
            point = segments[i].end;
            points.push_back(point);
        }
    }
    return points;
}

int main()
{
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (int i = 0; i < segments.size(); ++i)
    {
        cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    cout << points.size() << "\n";
    for (int i = 0; i < points.size(); ++i)
    {
        cout << points[i] << " ";
    }
}