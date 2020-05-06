// https://leetcode.com/problems/shuffle-an-array/
// https://leetcode.com/problems/shuffle-an-array/discuss/604955/C%2B%2B-Fisher-Yates-faster-than-100-4-lines-code
class Solution
{
    vector<int> numbers;

public:
    Solution(vector<int> &nums)
    {
        numbers = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return numbers;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> shuff(numbers);
        int n = numbers.size();
        for (int i = 0; i < shuff.size(); ++i)
        {
            int j = rand() % (n - i) + i;
            swap(shuff[i], shuff[j]);
        }
        return shuff;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */


// STL IMPLEMENTATION
class Solution {
    vector<int> numbers;
public:
    Solution(vector<int>& nums) {
        numbers = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return numbers;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuff(numbers);
        random_shuffle(shuff.begin(), shuff.end());
        return shuff;
    }
};