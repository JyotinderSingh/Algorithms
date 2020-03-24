#include <bits/stdc++.h>
using namespace std;

int RomanToDecimal(const string &s)
{
    unordered_map<char, int> T = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    // YOU CAN ALSO USE AN ARRAY TO STORE THE MAPPINGS FOR A FASTER SOLUTION
    // BUT IT WOULD RESULT IN SOME SPACE BEING WASTED
    // int T[128];
    //     T['I'] = 1;
    //     T['V'] = 5;
    //     T['X'] = 10;
    //     T['L'] = 50;
    //     T['C'] = 100;
    //     T['D'] = 500;
    //     T['M'] = 1000;

    int sum = T[s.back()];
    for (int i = s.length() - 2; i >= 0; --i)
    {
        if (T[s[i]] < T[s[i + 1]])
        {
            sum -= T[s[i]];
        }
        else
        {
            sum += T[s[i]];
        }
    }
    return sum;
}

// tester code
int main()
{
    string roman = "LIX"; // 59
    cout << roman << " : " << RomanToDecimal(roman) << endl;
    return 0;
}