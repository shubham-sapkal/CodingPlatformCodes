class Solution {
public:

    int solve(vector<int> &prices, int index, int fee, int buy, vector<vector<int>> &dp)
    {
        // base case
        if(index == prices.size())
            return 0;

        if(dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;

        if(buy)
        {
            profit = max( -prices[index] + solve(prices, index+1, fee, 0, dp), 0 + solve(prices, index+1, fee, 1, dp) );
        }
        else{
            profit = max( +prices[index] + solve(prices, index+1, fee, 1, dp) - fee, 0 + solve(prices, index+1, fee, 0, dp) );
        }

        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, fee, 1, dp);
    }
};