class Solution {
public:

    
    int minSideJumps(vector<int>& obstacles) {

        int n = obstacles.size()-1;
        vector<vector<int>> dp(4, vector<int>(n+1, 1e9));

        // analysic base case
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        // position
        for(int currpos=n-1; currpos>=0; currpos--)
        {
            for(int currlane=1; currlane<=3; currlane++)
            {
                 // check next position pe koyii obstacles nah hain
                if(obstacles[currpos+1] != currlane )
                {
                    // dp[currlane][currpos] = solve(obstacles, currlane, currpos+1, dp); 
                    dp[currlane][currpos] = dp[currlane][currpos+1];
                }
                else{
                    // obstacles hain 
                    // sideways jumps
                    int ans = 1e9;
                    for(int i=1; i<=3; i++)
                    {
                        if(currlane != i && obstacles[currpos] != i )
                            ans = min( ans, 1 + dp[i][currpos+1] );
                    }

                    dp[currlane][currpos] = ans;
                
                }
            }
        }

        // getting minimum from each lane
        return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));

    }
};