#include <bits/stdc++.h>
using namespace std;

double BuyAndSellStockTwice(vector<double> &prices)
{
    double min_price_so_far = numeric_limits<double>::max(), max_total_profit = 0;
    vector<double> first_buy_sell_profits(prices.size(), 0);

    // Forward Pass: for each day we calculate the maximum profit
    // if we sell on that day
    for (int i = 0; i < prices.size(); ++i)
    {
        min_price_so_far = min(min_price_so_far, prices[i]);
        max_total_profit = max(max_total_profit, prices[i] - min_price_so_far);
        first_buy_sell_profits[i] = max_total_profit;
    }

    // Backward pass: for each day calculate the maximum profit if we make
    // the second buy on that day
    double max_price_so_far = numeric_limits<double>::min();
    for (int i = prices.size() - 1; i > 0; --i)
    {
        max_price_so_far = max(max_price_so_far, prices[i]);
        max_total_profit = max(max_total_profit, max_price_so_far - prices[i] + first_buy_sell_profits[i - 1]);
    }
    return max_total_profit;
}

// Tester code
int main() {
    vector<double> prices{12, 11, 13, 9, 12, 8, 14, 13, 15};
    cout<<BuyAndSellStockTwice(prices);
}