#include <bits/stdc++.h>
using namespace std;

string SnakeString(const string &s)
{
    string result;
    for (int i = 1; i < s.size(); i += 4)
    {
        result += s[i];
    }
    for (int i = 0; i < s.size(); i += 2)
    {
        result += s[i];
    }
    for (int i = 3; i < s.size(); i += 4)
    {
        result += s[i];
    }
    return result;
}

// tester code
int main()
{
    string s = "Hello_World!";
    cout << SnakeString(s);
    return 0;
}