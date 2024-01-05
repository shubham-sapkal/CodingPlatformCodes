class Solution {
public:

    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if( i == a.size()) // word1 is smaller than word2
        {
            return b.size() - j;
        }

        if( j == b.size()) // word2 is smaller than word1
        {
            return a.size() - i;
        }

        if(dp[i][j] != -1 )
            return dp[i][j];

        int ans = 0;

        if(a[i] == b[j] ) // match
        {
            return dp[i][j] = solve(a, b, i+1, j+1, dp);
        }
        else{

            // insert
            int insertAns = 1 + solve(a, b, i, j+1, dp);

            // delete
            int deleteAns = 1 + solve(a, b, i+1, j, dp);

            // replace
            int replaceAns = 1 + solve(a, b, i+1, j+1, dp);

            ans = min(insertAns, min(deleteAns, replaceAns));

            return dp[i][j] = ans;
        }
    }

    int minDistance(string word1, string word2) {

        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));

        return solve(word1, word2, 0, 0, dp);
    }
};