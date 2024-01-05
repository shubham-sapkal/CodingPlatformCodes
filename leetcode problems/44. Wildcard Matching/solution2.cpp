class Solution {
public:

    bool isMatch(string s, string p) {

        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, 0));

        // 1st base case
        dp[0][0] = true;

        // 3rd base case
        for(int j=1; j<=p.size(); j++)
        {
            bool flag = true;
            for(int k=1; k<=j; k++)
            {
                if(p[k-1] != '*' ){
                    flag = false;
                    break;
                }
                    
            }
            dp[0][j] = flag;
        }

        for(int i=1; i<=s.size(); i++)
        {
            for(int j=1; j<=p.size(); j++)
            {
                // match
                if(s[i-1] == p[j-1] || p[j-1] == '?' )
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*' )
                {
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                }
                else
                    dp[i][j] = false;
            }
        }


        return dp[s.size()][p.size()];
    }
};