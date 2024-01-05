#include <bits/stdc++.h> 

// Following recursion, 2 states are changing, therefore we are applying 2D dp

int solve(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
{
    // base case
    if(index == 0)
    {
        // only only 1 item to steal, then just compare its weight with the knapsnak
        if(weight[0] <= capacity )
            return value[0];
        else
            return 0;
    }
    
    if(dp[index][capacity] != -1 )
        return dp[index][capacity];
    
    // include : including value if lie between capacity
    int include = 0;
    if(weight[index]  <= capacity)
    {
        include = value[index] + solve(weight, value, index-1, capacity-weight[index], dp);
    }
    
    // exclude
    int exclude = 0 + solve(weight, value, index-1, capacity, dp);
    
    // step 2 : store dp
    dp[index][capacity] = max(exclude, include);
    return dp[index][capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    // step 1: create dp array
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return solve(weight, value, n-1, maxWeight, dp);
}