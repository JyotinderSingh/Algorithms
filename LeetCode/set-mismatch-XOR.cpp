// https://leetcode.com/problems/set-mismatch/
// https://leetcode.com/problems/set-mismatch/discuss/105513/XOR-one-pass
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> count(nums.size(), 0);
        vector<int> ans(2);
        int x = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            x ^= nums[i] ^ (i + 1);
            if (++count[nums[i] - 1] == 2)
            {
                ans[0] = nums[i];
            }
        }
        ans[1] = x ^ ans[0];
        return {ans[0], ans[1]};
    }
};

// CONSTANT SPACE SOLUTION O(0)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        vector<int> ans(2);
        int x = 0;
        for(int i = 0; i < nums.size(); ++i){
            int val = abs(nums[i]);
            ans[1] ^= val ^ (i + 1);
            if(nums[val - 1] < 0){
                ans[0] = val;
            } else{
                nums[val - 1] = -nums[val - 1];
            }
        }
        ans[1] ^= ans[0];
        return {ans[0], ans[1]};
    }
};