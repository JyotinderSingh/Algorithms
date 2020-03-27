// Rabin-Karp algorithm
#include <bits/stdc++.h>
using namespace std;

int RabinKarp(const string &t, const string &s)
{
    if (s.size() > t.size())
    {
        return -1;
    }

    const int kBase = 26;
    int t_hash = 0, s_hash = 0; // hash codes for substrings of t and s
    int power_s = 1;            // kBase ^ |s|

    for (int i = 0; i < s.size(); ++i)
    {
        power_s = i ? power_s * kBase : 1;
        t_hash = t_hash * kBase + t[i];
        s_hash = s_hash * kBase + s[i];
    }

    for (int i = s.size(); i < t.size(); ++i)
    {
        // Checks if the two substrings are equal or not to protect against
        // hash collision
        if (t_hash == s_hash && !t.compare(i - s.size(), s.size(), s))
        {
            return i - s.size(); // Found a match!
        }

        // uses rolling hash to compute new hash code
        t_hash -= t[i - s.size()] * power_s;
        t_hash = t_hash * kBase + t[i];
    }

    if (t_hash == s_hash && !t.compare(t.size() - s.size(), s.size(), s))
    {
        return t.size() - s.size();
    }
    return -1; // s is not a substring of t
}

// tester code
int main()
{
    string text = "The quick brown fox jumped over the lazy dog";
    string substring1 = "fox";
    string substring2 = "Hello";
    cout << substring1 << " at " << RabinKarp(text, substring1) << endl;
    cout << substring2 << " at " << RabinKarp(text, substring2) << endl;
}