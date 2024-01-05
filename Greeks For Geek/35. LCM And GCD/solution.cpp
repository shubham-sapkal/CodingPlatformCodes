//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    // using euclid GCD
    
    long long LCM(long long A, long long B)
    {
        long long ans = A*B;
        
        return ans / GCD(A, B);
    }    
    
    long long GCD(long long A, long long B)
    {
        if(B == 0)
            return A;
        else
            return GCD(B, A%B);
    }
  
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        
        
        long long gcd = GCD(A, B);
        long long lcm = LCM(A, B);
        
        return {lcm, gcd};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends