// https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<long int> left_to_right(nums.size());
        vector<long int> right_to_left(nums.size());
        left_to_right[0] = nums[0], right_to_left[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = 1; i < nums.size(); ++i) {
            left_to_right[i] = left_to_right[i - 1] * nums[i];
            right_to_left[nums.size() - i - 1]  = right_to_left[(nums.size() - i - 1) + 1] * nums[nums.size() - i - 1]; 
        }

        if(nums.size() >= 2) {
            res[0] = right_to_left[1];
            res[nums.size() - 1] = left_to_right[nums.size() - 1 - 1];
        }
        for(int i = 1; i < nums.size() - 1; ++i) {
            res[i] = left_to_right[i - 1] * right_to_left[i+1];
        }
        return res;

    }
};