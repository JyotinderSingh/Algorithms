// https://leetcode.com/problems/house-robber-ii/
// https://leetcode.com/problems/house-robber-ii/discuss/227366/Thinking-process-from-easy-question-to-harder-question-within-the-same-question-set

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];

        int prev1 = 0, oneBeforePrev1 = 0;
        // If we consider robbing the first house, we can't rob the last house
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            int temp = prev1;
            prev1 = max(oneBeforePrev1 + nums[i], prev1);
            oneBeforePrev1 = temp;
        }

        int prev2 = 0, oneBeforePrev2 = 0;
        // If we consider robbing the last house, we can't rob the first house
        for (int i = 1; i < nums.size(); ++i)
        {
            int temp = prev2;
            prev2 = max(oneBeforePrev2 + nums[i], prev2);
            oneBeforePrev2 = temp;
        }
        return max(prev1, prev2);
    }
};