//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // backward check
    int solve(int index, int diff, int A[], unordered_map<int, int> dp[])
    {
        // base case
        if(index < 0)
            return 0;
            
        int ans=0;
        
        if(dp[index].count(diff))
            return dp[index][diff];
        
        
        for(int prev=index-1; prev>=0; prev--)
        {
            if(A[index] - A[prev] == diff)
                ans = max(ans, 1 + solve(prev, diff, A, dp));
        }
        
        return dp[index][diff] = ans ;
    }

    int lengthOfLongestAP(int A[], int n) {

        if(n <= 2)
            return n;
            
        unordered_map<int, int> dp[n+1];
        
    
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                ans = max(ans, 2 + solve(i, A[j] - A[i], A, dp));        
            }
        }
        
        return ans;


    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends