// https://leetcode.com/problems/product-of-array-except-self/
// https://leetcode.com/problems/product-of-array-except-self/discuss/65622/Simple-Java-solution-in-O(n)-without-extra-space/67603
// https://leetcode.com/problems/product-of-array-except-self/discuss/65622/Simple-Java-solution-in-O(n)-without-extra-space

///// O(N) time, O(1) space
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 1);
        int left = 1;
        for (int i = 0; i < n; ++i)
        {
            if (i > 0)
            {
                left = left * nums[i - 1];
            }
            res[i] *= left;
        }

        int right = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            if (i < n - 1)
            {
                right = right * nums[i + 1];
            }
            res[i] *= right;
        }
        return res;
    }
};

//////////////////////////////////////////
///// O(N) time, O(N) space //////////////

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res(nums.size());
        if (nums.empty())
            return res;
        vector<int> lefts(nums.size());
        vector<int> rights(nums.size());
        lefts[0] = nums[0], rights.back() = nums.back();

        for (int i = 1; i < nums.size(); ++i)
            lefts[i] = lefts[i - 1] * nums[i];
        for (int i = nums.size() - 2; i >= 0; --i)
            rights[i] = rights[i + 1] * nums[i];
        for (int i = 0; i < res.size(); ++i)
        {
            res[i] = (i > 0 ? lefts[i - 1] : 1) * (i < res.size() - 1 ? rights[i + 1] : 1);
        }
        return res;
    }
};

//////////////////////////////////////////////////////////

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res(nums.size());
        vector<long int> left_to_right(nums.size());
        vector<long int> right_to_left(nums.size());
        left_to_right[0] = nums[0], right_to_left[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = 1; i < nums.size(); ++i)
        {
            left_to_right[i] = left_to_right[i - 1] * nums[i];
            right_to_left[nums.size() - i - 1] = right_to_left[(nums.size() - i - 1) + 1] * nums[nums.size() - i - 1];
        }

        if (nums.size() >= 2)
        {
            res[0] = right_to_left[1];
            res[nums.size() - 1] = left_to_right[nums.size() - 1 - 1];
        }
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            res[i] = left_to_right[i - 1] * right_to_left[i + 1];
        }
        return res;
    }
};