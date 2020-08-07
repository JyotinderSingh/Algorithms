// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;
        vector<int> profits(prices.size(), 0);
        int maxSoFar = 0, profitToday = INT_MIN, leastPrice = prices.front();
        for (int i = 0; i < prices.size(); ++i)
        {
            profitToday = prices[i] - leastPrice;
            profits[i] = max(profitToday, maxSoFar);

            // Update limits
            maxSoFar = max(maxSoFar, profits[i]);
            leastPrice = min(leastPrice, prices[i]);
        }
        int maxPrice = prices.back(), finalProfit = 0;
        for (int i = prices.size() - 1; i > 0; i--)
        {
            finalProfit = max(finalProfit, maxPrice - prices[i] + profits[i - 1]);
            maxPrice = max(maxPrice, prices[i]);
        }
        return max(maxSoFar, finalProfit);
    }
};

////////////////SAME BUT DIFFERENT/////////////////////

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
        {
            return 0;
        }
        int least_price = prices[0];
        int max_profit_till_now = 0;
        vector<int> max_profit_today(prices.size(), 0);
        for (int i = 0; i < prices.size(); ++i)
        {
            max_profit_till_now = max(max_profit_till_now, prices[i] - least_price);
            least_price = min(least_price, prices[i]);
            max_profit_today[i] = max_profit_till_now;
        }
        int final_profit = 0, max_price = prices.back();
        for (int i = prices.size() - 1; i > 0; i--)
        {
            final_profit = max(final_profit, max_price - prices[i] + max_profit_today[i - 1]);
            max_price = max(max_price, prices[i]);
        }
        return max(final_profit, max_profit_today.back());
    }
};