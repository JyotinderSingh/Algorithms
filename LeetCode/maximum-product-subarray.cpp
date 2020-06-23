// https://leetcode.com/problems/maximum-product-subarray/
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int res = nums[0];

        for (int i = 1, curMax = res, curMin = res; i < nums.size(); ++i)
        {
            // If we encounter a negative number, the largest product that we've found
            // till now, will become the smallest once multiplied.
            // And the smallest product we've found till now will become the largest
            // once multiplied
            if (nums[i] < 0)
            {
                swap(curMin, curMax);
            }

            // Similar to Kadane
            curMin = min(nums[i], curMin * nums[i]);
            curMax = max(nums[i], curMax * nums[i]);

            // update the result if needed
            res = max(res, curMax);
        }
        return res;
    }
};
