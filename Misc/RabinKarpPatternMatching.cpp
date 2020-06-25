#include <bits/stdc++.h>
using namespace std;

const int prime = 101;

long createHash(const string& str, int end);
long recalculateHash(const string& str, int oldIndex, int newIndex, long oldHash, int patternLen);
bool checkEqual(const string& str1, int start1, int end1, const string& str2, int start2, int end2);

int RabinKarp(const string &text, const string &pattern)
{
    if (pattern.size() > text.size())
    {
        return -1;
    }

    int M = pattern.size(), N = text.size();

    long textHash = createHash(text, M - 1);
    long patternHash = createHash(pattern, M - 1);

    for (int i = 1; i <= N - M + 1; ++i)
    {
        if (textHash == patternHash && checkEqual(text, i - 1, i + M - 2, pattern, 0, M - 1))
        {
            return i - 1;
        }
        if (i < N - M + 1)
        {
            textHash = recalculateHash(text, i - 1, i + M - 1, textHash, M);
        }
    }
    return -1;
}

long recalculateHash(const string& str, int oldIndex, int newIndex, long oldHash, int patternLen)
{
    long newHash = oldHash - str[oldIndex];
    newHash = newHash / prime;
    newHash += str[newIndex] * pow(prime, patternLen - 1);
    return newHash;
}

long createHash(const string& str, int end)
{
    long hash = 0;
    for (int i = 0; i <= end; i++)
    {
        hash += str[i] * pow(prime, i);
    }
    return hash;
}

bool checkEqual(const string& str1, int start1, int end1, const string& str2, int start2, int end2)
{
    if (end1 - start1 != end2 - start2)
    {
        return false;
    }
    while (start1 <= end1 && start2 <= end2)
    {
        if (str1[start1++] != str2[start2++])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << RabinKarp("JyotinderSingh", "yo") << endl;
    cout << RabinKarp("JyotinderSingh", "otind") << endl;
    cout << RabinKarp("JotinderSingh", "yotine") << endl;
    cout << RabinKarp("JyotinderSingh", "Singh") << endl;
    cout << RabinKarp("JyotinderSingh", "JyotinderSingh") << endl;
    cout << RabinKarp("JyotinderSingh", "Jyo") << endl;
}