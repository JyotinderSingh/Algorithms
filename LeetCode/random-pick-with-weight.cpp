// https://leetcode.com/problems/random-pick-with-weight/discuss/671460/Detailed-Explanation-or-Summary-of-2-different-solutions
// https://leetcode.com/problems/random-pick-with-weight/discuss/671550/Cumulative-Distribution-Function-or-Explanation-or-Binary-and-Linear-Search-code
class Solution
{
    vector<int> cdf;

public:
    Solution(vector<int> &w)
    {
        cdf = vector<int>(w.size());
        cdf[0] = w[0];
        for (int i = 1; i < cdf.size(); ++i)
        {
            cdf[i] = cdf[i - 1] + w[i];
        }
    }

    int pickIndex()
    {
        int x = cdf.back();
        int index = rand() % x;
        auto it = upper_bound(cdf.begin(), cdf.end(), index);
        return it - cdf.begin();
    }
};