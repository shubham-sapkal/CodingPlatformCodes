class Solution {
public:

    int solve(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp)
    {
        // base case
        if(index == satisfaction.size())
        {
            return 0;
        }

        // if dp record found
        if(dp[index][time] != -1 )
            return dp[index][time];
        
        // include
        int include = (satisfaction[index] * (time+1)) + solve(satisfaction, index+1, time+1, dp);

        // exclude
        int exclude = solve(satisfaction, index+1, time, dp); // no dish created so time will be same
        
        
        dp[index][time] = max(include, exclude);
        return dp[index][time];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(satisfaction, 0, 0, dp);

        
    }
};