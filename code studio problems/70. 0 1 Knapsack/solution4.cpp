#include <bits/stdc++.h> 

// Following recursion, 2 states are changing, therefore we are applying 2D dp


int knapsack(vector<int> weight, vector<int> value, int n, int capacity) 
{
    // step 1: create dp array
    
//     vector<int> prev(capacity+1, 0);
    vector<int> curr(capacity+1, 0);
    
    // step 2 : analysis base case
    for(int w=weight[0]; w<=capacity; w++)
    {
        if(weight[0] <= capacity)
            curr[w] = value[0];
        else
            curr[w] = 0;
    }
    
    
    for(int index = 1; index<n; index++)
    {
        for(int w=capacity; w>=0; w--)
        {
            int include = 0;
            if(weight[index] <= w )
            {
                include = value[index] + curr[w-weight[index]];
            }
            
            int exclude = 0 + curr[w];
            
            curr[w] = max(include, exclude);
            
        }
        
    }
    
    return curr[capacity];
	
}