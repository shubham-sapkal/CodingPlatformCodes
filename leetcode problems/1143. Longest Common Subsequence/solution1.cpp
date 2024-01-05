class Solution {
public:

    int solve(string& text1, string& text2, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if( i == text1.size() || j == text2.size() )
        {
            return 0;
        }

        if(dp[i][j] != -1 )
            return dp[i][j];

        int ans = 0;
        if(text1[i] == text2[j] ) // match
        {
            ans =  1 + solve(text1, text2, i+1, j+1, dp);
        }
        else{ // not match
            ans =  max( solve(text1, text2, i+1, j, dp), solve(text1, text2, i, j+1, dp)  );
        }

        return dp[i][j] = ans;

    }

    int longestCommonSubsequence(string text1, string text2) {
        
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1) );
        return solve(text1, text2, 0, 0, dp);

    }
};