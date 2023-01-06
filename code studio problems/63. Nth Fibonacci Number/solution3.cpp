#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    cin>>n;
    
    if(n == 1 || n == 0)
    {
        cout << n;
        return 0;
    }
    

    
    int prev1 = 1;
    int prev2 = 0;
    
    for(int i=2; i<=n; i++)
    {
        int curr = prev1 + prev2;
        // shifting 
        prev2 = prev1;
        prev1 = curr;
    }
    
    cout<< prev1 << endl;
    
}