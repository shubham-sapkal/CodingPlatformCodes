#include<vector>
#define MOD 1000000007

long long int solve(int n, vector<int> &dp)
{
    // base case
    if(n == 1)
        return 0;
    
    if(n == 2)
        return 1;
    
    if(dp[n] != -1 )
        return dp[n];
    
    dp[n] = (((n-1)%MOD) * ( (solve(n-1, dp)%MOD) + (solve(n-2, dp)%MOD)))%MOD;
    
    return dp[n];
}

long long int countDerangements(int n) {
    
    vector<int> dp(n+1, -1);
    
    return solve(n, dp);
    
}