// https://leetcode.com/problems/single-number-ii/
// https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // All elements appear thrice; K = 3,
        // except one, which appears once, p = 1 (our solution doesn't need this info tho)

        // x1, x2 are used to reperesent the first and second bits of the counter respectively
        int x1 = 0, x2 = 0, mask = 0;

        for (const auto &num : nums)
        {
            // A bit of counter only becomes one if all prev bits (of the counter) are one,
            // and the corrosponding bit of the current number if also one
            x2 ^= x1 & num;
            x1 ^= num;
            mask = ~(x1 & x2); // inversion of 3 (=K) in binary

            // Apply mask to each of the bits of the counter
            x2 &= mask;
            x1 &= mask;
        }
        return (x1 | x2);
    }
};