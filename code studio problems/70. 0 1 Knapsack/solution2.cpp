#include <bits/stdc++.h> 

// Following recursion, 2 states are changing, therefore we are applying 2D dp


int knapsack(vector<int> weight, vector<int> value, int n, int capacity) 
{
    // step 1: create dp array
    vector<vector<int>> dp(n, vector<int>(capacity+1, 0));
    
    
    // step 2 : analysis base case
    for(int w=weight[0]; w<=capacity; w++)
    {
        if(weight[0] <= capacity)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }
    
    for(int index = 1; index<n; index++)
    {
        for(int w=0; w<=capacity; w++)
        {
            int include = 0;
            if(weight[index] <= w )
            {
                include = value[index] + dp[index-1][w-weight[index]];
            }
            
            int exclude = 0 + dp[index-1][w];
            
            dp[index][w] = max(include, exclude);
        }
    }
    
    return dp[n-1][capacity];
	
}