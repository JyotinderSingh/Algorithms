#include <iostream>
using namespace std;

void reverse(char *begin, char *end);

void reverseWords(char *s)
{
    char *begin = s;
    char *end = s;

    while (*end)
    {
        *end++;

        if (*end == '\0')
        {
            reverse(begin, end - 1);
        }
        else if (*end == '.')
        {
            reverse(begin, end - 1);
            begin = end + 1;
        }
    }

    reverse(s, end - 1);
}

void reverse(char *begin, char *end)
{
    char temp;
    while (begin < end)
    {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

int main()
{
    char s[100];
    cin >> s;
    reverseWords(s);
    cout << "Reversed string is " << s;
    return 0;
}