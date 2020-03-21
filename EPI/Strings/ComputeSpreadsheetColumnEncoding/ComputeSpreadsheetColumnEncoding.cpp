#include <bits/stdc++.h>
using namespace std;

int SSDecodeColID(const string &col)
{
    int ret = 0;
    for (char c : col)
    {
        // we add 1 in the end as A refers to 1 and not 0
        ret = ret * 26 + c - 'A' + 1;
    }

    return ret;
}

// tester
int main()
{
    string column = "ZZ";
    cout << SSDecodeColID(column);
    return 0;
}