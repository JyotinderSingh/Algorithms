#include <bits/stdc++.h>
using namespace std;

struct item
{
    long int value;
    double weight;
    item() {}
    item(long int value, long int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};

bool cmp(item a, item b)
{
    double ratio1 = ((double)a.value / a.weight);
    double ratio2 = ((double)b.value / b.weight);
    return ratio1 > ratio2;
}

double fractionalKnapsack(item arr[], double W, long int n)
{
    sort(arr, arr + n, cmp);
    double V = 0;
    long int i = 0;
    for (long int i = 0; i < n; ++i)
    {
        if (W == 0)
        {
            return V;
        }
        double a = min(arr[i].weight, W);
        V += a * (arr[i].value / arr[i].weight);
        W -= a;
        arr[i].weight -= a;
    }
    return V;
}

int main()
{
    long int n;
    double W;
    cin >> n >> W;
    item arr[n];
    long int val, weight;
    for (long int i = 0; i < n; ++i)
    {
        cin >> val >> weight;
        arr[i].value = val;
        arr[i].weight = weight;
    }
    cout.precision(10);
    cout << fractionalKnapsack(arr, W, n);

    return 0;
}