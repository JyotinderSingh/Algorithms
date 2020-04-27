// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit_till_now = 0;
        int least_price = INT_MAX;
        int profit_today = 0;
        for (auto price : prices)
        {
            profit_today = price - least_price;
            least_price = min(least_price, price);
            max_profit_till_now = max(max_profit_till_now, profit_today);
        }
        return max_profit_till_now;
    }
};