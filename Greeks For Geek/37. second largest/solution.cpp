//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    
	    int largest = arr[0];
	    int secondlargest = -1;
	    
	    for(int i=1; i<n; i++)
	    {
	        
	        if(arr[i] == largest || arr[i] == secondlargest )
	            continue;
	        
	        if(arr[i] > largest)
	        {
	            if(secondlargest < largest)
	                secondlargest = largest;
	            
	            largest = arr[i];
	            
	        }
	        else if(arr[i] > secondlargest)
	        {
	            secondlargest = arr[i];
	        }
	        
	       // cout << "largest = " << largest << " second = " << secondlargest << endl;
	        
	    }
	    
	    return secondlargest;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends