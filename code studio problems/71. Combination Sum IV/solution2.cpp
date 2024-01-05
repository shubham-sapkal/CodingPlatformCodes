#include <bits/stdc++.h>

int findWays(vector<int> &num, int tar)
{
    vector<int> dp(tar+1, 0);
    
    dp[0] = 1;
    
    // traversing from target 1 to tar
    for(int i=1; i<=tar; i++)
    {
        // tarversing on num array
        for(int j=0; j<num.size(); j++)
        {
            if(i - num[j] >= 0 )
                dp[i] += dp[i-num[j]];
            
        }
    }
    
    return dp[tar];
}