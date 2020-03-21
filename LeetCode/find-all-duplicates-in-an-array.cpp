// https://leetcode.com/problems/find-all-duplicates-in-an-array/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // when we find a number i, flip the number at position i-1 to negative. 
        // if the number at position i-1 is already negative, i is the number that occurs twice.
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0) {
                res.push_back(abs(nums[i]));
            }
            nums[index] *= -1;
        }
        return res;
    }
};