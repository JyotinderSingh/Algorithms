// https://leetcode.com/problems/find-the-duplicate-number/
// https://leetcode.com/problems/find-the-duplicate-number/discuss/602864/Floyd's-Tortoise-and-Hare-Cycle-Detection-JAVA-Faster-than-100
// https://leetcode.com/problems/find-the-duplicate-number/discuss/605515/Cycle-Detection-Algorithm-O(n)-(Detailed-Explanation)

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        if (!nums.size())
        {
            return -1;
        }
        int slow = nums[0], fast = nums[0];
        // use a do while loop to run it for the first time,
        // when both pointers are at the same position
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};