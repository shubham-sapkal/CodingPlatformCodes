#include<bits/stdc++.h>

int solve(int n, int x, int y, int z, vector<int> &dp)
{
    // base case
    if(n==0)
    {
        return 0;
    }
    
    if(n < 0)
    {
        return INT_MIN;
    }
    
    if(dp[n] != 0)
    {
        return dp[n];
    }
    
    //call for x
    int ansx = solve(n-x, x, y, z, dp) + 1;
    // call for y
    int ansy = solve(n-y, x, y, z, dp) + 1;
    // call for z    
    int ansz = solve(n-z, x, y, z, dp) + 1;
    
    
    
    dp[n] = max(ansx, max(ansy, ansz));
    return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
    vector<int> dp(n+1, 0);
    
    int ans = solve(n, x, y, z, dp);
    
    return ans < 0 ? 0 : ans;
}