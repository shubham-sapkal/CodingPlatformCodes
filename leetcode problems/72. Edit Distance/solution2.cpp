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

    int minDistance(string a, string b) {

        vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));

        for(int j=0; j<b.size(); j++)
        {
            dp[a.size()][j] = b.size() - j;
        }

        for(int i=0; i<a.size(); i++)
        {
            dp[i][b.size()] = a.size() - i;
        }

        for(int i=a.size()-1; i>=0; i--)
        {
            for(int j=b.size()-1; j>=0; j--)
            {
                if(a[i] == b[j] ) // match
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else{

                    // insert
                    int insertAns = 1 + dp[i][j+1];

                    // delete
                    int deleteAns = 1 + dp[i+1][j];

                    // replace
                    int replaceAns = 1 + dp[i+1][j+1];

                    int ans = min(insertAns, min(deleteAns, replaceAns));

                    dp[i][j] = ans;
                }
            }
        }

        return dp[0][0];

    }
};