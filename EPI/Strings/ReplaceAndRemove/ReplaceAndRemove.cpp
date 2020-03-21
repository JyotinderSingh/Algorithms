// A program that takes as input an array of characters and removes each 'b' and replaces each 'a' by two 'd's.
// you are also given an integer 'size' that denotes the number of entries that the operation is to be applied to
#include <bits/stdc++.h>
using namespace std;

int ReplaceAndRemove(int size, char s[])
{
    // Forward iteration: Remove all the 'b's and count the number of 'a's
    int write_idx = 0, a_count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (s[i] != 'b')
        {
            s[write_idx++] = s[i];
        }
        if (s[i] == 'a')
        {
            a_count++;
        }
    }

    // Backward itetration: replace all the 'a's with 'dd's starting from the end
    // we put cur_idx = write_idx - 1
    //if last element was b then anyway we need to start scanning from the element before as 'b' is to be skipped
    // if not, then we had post incremented write_idx on the last pass of the for loop above
    int cur_idx = write_idx - 1;
    write_idx = write_idx - 1 + a_count;
    int final_size = write_idx + 1;
    while (cur_idx >= 0)
    {
        if (s[cur_idx] == 'a')
        {
            s[write_idx--] = 'd';
            s[write_idx--] = 'd';
        }
        else
        {
            s[write_idx--] = s[cur_idx];
        }
        --cur_idx;
    }
    return final_size;
}

// tester code
int main()
{
    const int size = 35;
    char s[size] = {'a', 'b', 'a', 'c'};
    for (char c : s)
    {
        cout << c;
    }
    cout << endl;
    ReplaceAndRemove(size, s);
    for (char c : s)
    {
        cout << c;
    }
}