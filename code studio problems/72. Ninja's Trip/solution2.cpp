
    
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n+1, INT_MAX);
    
    dp[n] = 0;
    
    for(int index=n-1; index>=0; index--)
    {
        // 1 day pass
        int option1 =  cost[0] + dp[index+1];

        // 7 day pass
        // our i is at index, shift i to the 7 day next
        int i;
        for(i=index; i < n && days[i]<days[index]+7; i++);
        int option2 = cost[1] + dp[i];

        // 30 day pass
        // our i is at index, shift i to the 30 dayy next
        for(i=index; i < n && days[i]<days[index]+30; i++);
        int option3 = cost[2] + dp[i];

        dp[index] =  min(option1, min(option2, option3));
    }
    
    return dp[0];
    
}