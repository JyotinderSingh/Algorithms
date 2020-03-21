#include <bits/stdc++.h>
using namespace std;

void ReverseWords(string *s)
{
    // Reverse the whole string
    reverse(s->begin(), s->end());

    // reverse individual letters
    size_t start = 0, end;
    while ((end = s->find(" ", start)) != string::npos)
    {
        reverse(s->begin() + start, s->begin() + end);
        start = end + 1;
    }

    // Reverse the last word
    reverse(s->begin() + start, s->end());
}

// tester code
int main()
{
    string *s = new string("Alice likes Bob");
    cout << *s << endl;
    ReverseWords(s);
    cout << *s << endl;
    return 0;
}