#include <bits/stdc++.h>
using namespace std;

string ConstructFromBase(int, int);

string ConvertBase(const string &s, int b1, int b2)
{
    bool is_negative = s.front() == '-';
    int x = 0;
    for (int i = (is_negative ? 1 : 0); i < s.size(); ++i)
    {
        x *= b1;
        x += isdigit(s[i]) ? s[i] - '0' : s[i] - 'A' + 10;
    }
    return (is_negative ? "-" : "") + (x == 0 ? "0" : ConstructFromBase(x, b2));
}

string ConstructFromBase(int x, int base)
{
    return x == 0 ? "" : ConstructFromBase(x / base, base) + (char)(x % base >= 10 ? 'A' + x % base - 10 : '0' + x % base);
}


// tester code
int main()
{
    string num = "615";
    int b1 = 7, b2 = 13;
    cout << ConvertBase(num, b1, b2);
}