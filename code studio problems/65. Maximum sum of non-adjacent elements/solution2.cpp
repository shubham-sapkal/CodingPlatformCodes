#include <bits/stdc++.h>


int maximumNonAdjacentSum(vector<int> &nums){

    int n = nums.size();
    
    vector<int> dp(n, 0);
    
    dp[0] = nums[0];
    
    for(int i=1; i<n; i++)
    {
        int include = dp[i-2]+nums[i];
        int exclude = dp[i-1];
        dp[i] = max(include, exclude);
    }
    
    return dp[n-1];
    
}