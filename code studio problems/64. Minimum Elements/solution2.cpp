#include <bits/stdc++.h> 

int solve(vector<int> &num, int x)
{
    vector<int> dp(x+1, INT_MAX); // we are applying solution from bottom that why we take INT_MAX to all dp elements
    
    dp[0] = 0;
    
    for(int i=1; i<=x; i++)
    {
        // trying to solve for every amount figure from 1 to x
        for(int j=0; j<num.size(); j++)
        {
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX )
                dp[i] = min(dp[i], 1+ dp[i-num[j]]);
        }
    }
    
    return dp[x] == INT_MAX ? -1 : dp[x];
    
}

int minimumElements(vector<int> &num, int x)
{
    
    return solve(num, x);
    
}