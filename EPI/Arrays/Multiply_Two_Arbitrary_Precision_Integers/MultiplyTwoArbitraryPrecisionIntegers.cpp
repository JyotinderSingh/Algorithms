#include <bits/stdc++.h>
using namespace std;

vector<int> Multiply(vector<int> num1, vector<int> num2)
{
    int sign = num1.front() < 0 ^ num2.front() < 0 ? -1 : 1;
    num1.front() = abs(num1.front()), num2.front() = abs(num2.front());

    vector<int> result(num1.size() + num2.size(), 0);

    for (int i = num1.size() - 1; i >= 0; --i)
    {
        for (int j = num2.size() - 1; j >= 0; --j)
        {
            result[i + j + 1] += num1[i] * num2[j];
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }

    // NOTE
    // find_if_not returns the iterator to an element, for which the 
    // given predicate returns false.
    // i.e. it slices the array, starting from the first non-zero position
    // till the end.
    result = vector<int>{find_if(result.begin(), result.end(), [](int a) {
                                 return a;
                             }),
                             result.end()};
    if (result.empty())
    {
        return {0};
    }
    result.front() *= sign;
    return result;
}

// Tester code
int main()
{
    vector<int> num1{1, 2, 3};
    vector<int> num2{9,8,7};
    vector<int> res = Multiply(num1, num2);
    for(auto i: res){
        cout<<i;
    }
}