#include <bits/stdc++.h>
using namespace std;

string Decoding(const string &s)
{
    int count = 0;
    string result;
    for (const char &c : s)
    {
        if (isdigit(c))
        {
            count = count * 10 + c - '0';
        }
        else
        {
            // c is a letter of the alphabet
            result.append(count, c);
            count = 0;
        }
    }
    return result;
}

string Encoding(const string &s)
{
    int count = 1;
    string result;
    for (int i = 1; i <= s.size(); ++i)
    {
        if (i == s.size() || s[i] != s[i - 1])
        {
            // found new character so write the count of the previous one
            // or end of string, so write count of last character
            result += to_string(count) + s[i - 1];
            count = 1;
        }
        else
        {
            // s[i] == s[i  -1]
            count++;
        }
    }
    return result;
}

// tester code
int main()
{
    string stringToBeDecoded = "4a1b3c2a";
    cout << stringToBeDecoded << " : " << Decoding(stringToBeDecoded) << endl;
    string stringToBeEncoded = "aaaabcccaa";
    cout << stringToBeEncoded << " : " << Encoding(stringToBeEncoded);
    return 0;
}