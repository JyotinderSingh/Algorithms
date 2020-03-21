// for the purpose of this problem define a palindromic string to be a string
// which when all the nonalphanumeric charaters are removed reads the same
// front to back ignoring the case
#include <bits/stdc++.h>
using namespace std;

bool IsPalindrome(const string &s)
{
    // i moves forward and j moves backward
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        while (!isalnum(s[i]) && i < j)
        {
            i++;
        }
        while (!isalnum(s[j]) && i < j)
        {
            j--;
        }
        if (tolower(s[i]) != tolower(s[j]))
        {
            return false;
        }
        i++, j--;
    }
    return true;
}

// tester code
int main()
{
    string s1 = "A man, a plan, a canal, Panama";
    cout << s1 << " - " << IsPalindrome(s1) << endl;
    string s2 = "Ray a Ray";
    cout << s2 << " - " << IsPalindrome(s2);
    return 0;
}