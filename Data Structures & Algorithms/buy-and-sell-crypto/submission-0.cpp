class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int r = prices.size()-1;
        int maxSell = 0;
        int maxProfit = 0;
        while(r >= 0)
        {
            if(prices[r] < maxSell)
            {
                int profit = maxSell-prices[r];
                maxProfit = std::max(maxProfit, profit);

            }
            else
            {
                maxSell = prices[r];
            }
            r--;
        }
        return maxProfit;
    }
};
