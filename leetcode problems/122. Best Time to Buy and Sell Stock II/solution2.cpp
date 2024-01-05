class Solution {
public:
   
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int index=n-1; index>=0; index--)
        {
            for(int buy=0; buy<=1; buy++)
            {

                int profit = 0;
                if(buy)  // if buy is allowed
                {
                    profit = max( -prices[index] + dp[index+1][0], 0 + dp[index+1][1]  );
                }
                else{
                    profit = max( +prices[index] + dp[index+1][1], 0 + dp[index+1][0] );
                }

                dp[index][buy] = profit;

            }
        }

        return dp[0][1];
    }
};