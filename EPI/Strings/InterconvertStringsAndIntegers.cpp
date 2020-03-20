#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

string IntToString(int x)
{
    bool is_negative = false;
    if (x < 0)
    {
        x = -x, is_negative = true;
    }
    string s;
    do
    {
        s += '0' + x % 10;
        x /= 10;
    } while (x);

    if (is_negative)
    {
        s += '-'; // adds the negative sign back
    }
    reverse(s.begin(), s.end());
    return s;
}

int StringToInt(const string &s)
{
    bool is_negative = s[0] == '-';
    int result = 0;
    for (int i = s[0] == '-' ? 1 : 0; i < s.size(); ++i)
    {
        int digit = s[i] - '0';
        result = result * 10 + digit;
    }
    return is_negative ? -result : result;
}

// tester code
int main()
{
    string s = "-12345";
    cout << "\nString is: " << s << endl;
    cout << "StringToInteger result: " << StringToInt(s);
    int num = -54321;
    cout << "\nNumber is " << num << endl;
    cout << "IntToString result: " << IntToString(num);
}