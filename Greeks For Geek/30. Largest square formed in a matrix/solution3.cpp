//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

   

    int maxSquare(int n, int m, vector<vector<int>> mat){
        
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        
        int maxi = 0;
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                
                if(mat[i][j] == 1 )
                {
                     curr[j] =  1 + min(right, min(diagonal, down));
                     maxi = max(maxi, curr[j]);
                    //  return dp[i][j];
                }
                else{
                     curr[j] = 0;
                }
            }
            
            next = curr;
        }
        
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends