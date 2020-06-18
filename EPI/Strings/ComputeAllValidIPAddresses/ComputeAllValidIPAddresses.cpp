#include <bits/stdc++.h>
using namespace std;

bool IsValidPart(const string &s)
{
    if (s.size() > 3)
    {
        return false;
    }
    // "00", "000", "01" are not valid but "0 is valid
    if (s.front() == '0' && s.size() > 1)
    {
        return false;
    }

    int val = stoi(s);
    return val <= 255 && val >= 0;
}

vector<string> GetValidIPAddress(const string &s)
{
    vector<string> result;
    for (size_t i = 1; i < 4 && i < s.size(); ++i)
    {
        // start from 0, and take i digits
        auto first = s.substr(0, i);
        if (IsValidPart(first))
        {
            for (size_t j = i + 1; i + j < s.size() && j < 4; ++j)
            {
                // start from i'th index, and take j digits
                auto second = s.substr(i, j);
                if (IsValidPart(second))
                {
                    for (size_t k = 1; i + j + k < s.size() && k < 4; ++k)
                    {
                        auto third = s.substr(i + j, k), fourth = s.substr(i + j + k);
                        if (IsValidPart(third) && IsValidPart(fourth))
                        {
                            result.push_back(first + "." + second + "." + third + "." + fourth);
                        }
                    }
                }
            }
        }
    }
    return result;
}

//tester code
int main()
{
    string IP = "19216811";
    for (auto s : GetValidIPAddress(IP))
    {
        cout << s << endl;
    }
    return 0;
}