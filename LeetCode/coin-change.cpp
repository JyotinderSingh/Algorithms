// https://leetcode.com/problems/coin-change/
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> change(amount + 1, amount + 1);
        change[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for (auto coin : coins)
            {
                if (coin <= i)
                {
                    change[i] = min(change[i], change[i - coin] + 1);
                }
            }
        }
        return change[amount] > amount ? -1 : change[amount];
    }
};
