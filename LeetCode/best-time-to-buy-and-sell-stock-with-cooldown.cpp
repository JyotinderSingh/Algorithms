// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/240097/Come-on-in-you-will-not-regret-most-general-java-code-like-all-other-DP-solutions

////////// OPTIMIZED DP //////////
///// O(N) TIME + O(1) SPACE /////
//////////////////////////////////

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;

        // represents max profit at the end of day[i]
        vector<int> M(prices.size(), 0);
        int maxDiff = INT_MIN; // M[j - 2] - prices[j]
        int n = prices.size();

        for (int i = 0; i < prices.size(); ++i)
        {
            if (i < 2)
            {
                // M[-2] = M[-1] = 0
                // M[-2] - prices[i] or M[-1] - prices[i] => -prices[i]
                maxDiff = max(maxDiff, -prices[i]);
            }

            if (i == 0)
            {
                M[0] = 0;
            }
            else if (i == 1)
            {
                M[1] = max(prices[1] - prices[0], 0);
            }
            else
            {
                /*
                * M[i - 1] -> in case 'i' is a cooldown day 
                * maxDiff + prices[i] ==> note that here maxDiff is equal to M[i - 2] - prices[i] 
                * from previous iteration (maximal, might be from further before also) - but basically
                * maxDiff is equivalent to M[j - 2] - prices[j] for j from 0 to 'i - 1'
                */
                M[i] = max(M[i - 1], maxDiff + prices[i]);

                // Eqiuvalent to M[j - 2] - prices[j], for j from 0 to i 
                // (note: it'll be used in next iteration, so essentially then it would be 0 to 'i - 1')
                maxDiff = max(maxDiff, M[i - 2] - prices[i]);
            }
        }
        return M[n - 1];
    }
};

///////////////////////
/// SLOWER APPROACH ///
///////////////////////

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;

        // represents max profit at the end of day[i]
        vector<int> M(prices.size(), 0);
        int n = prices.size();

        for (int i = 0; i < prices.size(); ++i)
        {
            if (i == 0)
            {
                M[0] = 0;
            }
            else if (i == 1)
            {
                M[1] = max(prices[1] - prices[0], 0);
            }
            else
            {
                // In case day 'i' is a cooldown day
                M[i] = M[i - 1];

                // linear scan, in case of day 'i' being a selling day
                for (int j = 0; j < i; ++j)
                {
                    int prev = j >= 2 ? M[j - 2] : 0;
                    M[i] = max(M[i], prev + prices[i] - prices[j]);
                }
            }
        }
        return M[n - 1];
    }
};