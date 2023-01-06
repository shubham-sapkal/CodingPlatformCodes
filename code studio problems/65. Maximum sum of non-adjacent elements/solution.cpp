#include <bits/stdc++.h>

int solve(vector<int> &nums, int n, vector<int> &dp)
{
    // base case
    if(n < 0)
        return 0;
    
    if( n == 0)
        return nums[0];
    
    if(dp[n] != -1 )
        return dp[n];
    
    // include
    int include = solve(nums, n-2, dp) + nums[n];
    
    // exclude
    int exclude = solve(nums, n-1, dp);
    
    
    dp[n] = max(include, exclude);
    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums){
    // finding ans from right to left
    int n = nums.size();
    
    vector<int> dp(n, -1);
    
    int ans = solve(nums, n-1, dp);
    
    return ans;
}