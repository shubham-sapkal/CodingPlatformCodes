class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int index=n-1; index>=0; index--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                for(int limit=1; limit<=2; limit++)
                {

                    int profit = 0;
                    if(buy)  // if buy is allowed
                    {
                        profit = max( -prices[index] + dp[index+1][0][limit], 0 + dp[index+1][1][limit]  );
                    }
                    else{
                        profit = max( +prices[index] + dp[index+1][1][limit-1], 0 + dp[index+1][0][limit] );
                    }

                    dp[index][buy][limit] = profit;

                }
            }
        }

        return dp[0][1][2];
        
    }
};