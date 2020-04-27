// https://leetcode.com/problems/multiply-strings/
class Solution
{
public:
    string multiply(string num_1, string num_2)
    {
        vector<int> num1(num_1.size());
        vector<int> num2(num_2.size());
        for (int i = 0; i < num_1.size(); ++i)
        {
            num1[i] = num_1[i] - '0';
        }
        for (int i = 0; i < num_2.size(); ++i)
        {
            num2[i] = num_2[i] - '0';
        }

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
        result = vector<int>{find_if(result.begin(), result.end(), [](int a) {
                                 return a;
                             }),
                             result.end()};
        if (result.empty())
        {
            return "0";
        }
        result.front() *= sign;
        string res = "";
        for (auto i : result)
        {
            res += i + '0';
        }
        return res;
    }
};