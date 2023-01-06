class Solution {

private:
    int solve(int n, vector<int> &dp){
        
        // base case
        if(n < 0){
            return -1;
        }
        
        if(n == 1 || n == 0){
            return 1;
        }

        if(dp[n] != -1 )
        {
            return dp[n];
        }

    
        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }
    
public:
    
    int climbStairs(int n) {
        vector<int> dp(n+1);

        for(int i=0; i<=n; i++)
        {
            dp[i] = -1;
        }
        return solve(n, dp);
    }
};