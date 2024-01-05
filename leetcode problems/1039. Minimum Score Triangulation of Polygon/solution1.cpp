class Solution {
public:

    int solve(vector<int>& values, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if(i+1 == j)
            return 0;

        if(dp[i][j] != INT_MAX)
            return dp[i][j];

        int ans = INT_MAX;
        for(int k=i+1; k<j; k++ )
        {
            int score = values[i] * values[k] * values[j];
            dp[i][j] = min(dp[i][j], score + solve(values, i, k, dp) + solve(values, k, j, dp));
        }

        return dp[i][j];

    }

    int minScoreTriangulation(vector<int>& values) {

        int n = values.size()-1;
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));

        return solve(values, 0, values.size()-1, dp);
    }
};