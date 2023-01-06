#include <bits/stdc++.h>


int maximumNonAdjacentSum(vector<int> &nums){

    int n = nums.size();
   
    int prev2 = 0;
    int prev1 = nums[0];
    
    for(int i=1; i<n; i++)
    {
        int include = prev2+nums[i];
        int exclude = prev1;
        int curr = max(include, exclude);
        
        // shifting
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
    
}