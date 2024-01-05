//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        
        if(n <= 2)
            return n;
        
        int ans = 0;
        
        unordered_map<int, int> dp[n+1];
        
        // bottom up 
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                int diff = A[i] - A[j];
                
                int cnt = 1;
                
                // check if ans already present
                if(dp[j].count(diff))
                    cnt = dp[j][diff];
                    
                dp[i][diff] = 1 + cnt;
                
                ans = max(ans, dp[i][diff]);
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