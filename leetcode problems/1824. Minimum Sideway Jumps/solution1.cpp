class Solution {
public:

    int solve(vector<int> &obstacles, int currlane, int currpos, vector<vector<int>> &dp)
    {
        // base case
        if(currpos == obstacles.size()-1)
        {
            return 0;
        }

        if(dp[currlane][currpos] != -1 )
            return dp[currlane][currpos];

        // check next position pe koyii obstacles nah hain
        if(obstacles[currpos+1] != currlane )
        {
            // dp[currlane][currpos] = solve(obstacles, currlane, currpos+1, dp); 
            return solve(obstacles, currlane, currpos+1, dp);
        }
        else{
            // obstacles hain 
            // sideways jumps
            int ans = INT_MAX;
            for(int i=1; i<=3; i++)
            {
                if(currlane != i && obstacles[currpos] != i )
                    ans = min( ans, 1 + solve(obstacles, i, currpos, dp) );
            }

            dp[currlane][currpos] = ans;
            return dp[currlane][currpos];
        }
    }

    int minSideJumps(vector<int>& obstacles) {

        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n, -1));

        return solve(obstacles, 2, 0, dp);

    }
};