//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int index, int N, int arr[], int target, vector<vector<int>> &dp)
    {
        // base case
        if(index >= N)
            return 0;
            
        if(target < 0)
            return 0;
            
        if(target == 0)
            return 1;
            
        if(dp[index][target] != -1 )
            return dp[index][target];
            
        // include
        int include = solve(index+1, N, arr, target - arr[index], dp);
        
        // exclude
        int exclude = solve(index+1, N, arr, target, dp);
        
        return dp[index][target] = include || exclude;
    }

    int equalPartition(int N, int arr[])
    {
        int totalsum = accumulate(arr, arr+N, 0);
        
        if(totalsum%2 != 0)
            return 0;
            
        int target = totalsum/2;
        
        vector<vector<int>> dp(N, vector<int> (target+1, -1));
        
        return solve(0, N, arr, target, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends