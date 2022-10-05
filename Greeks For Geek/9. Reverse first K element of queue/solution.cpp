//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    
    // step 1: pop k element from queue and push it to stack
    stack<int> s;
    
    for(int i=0; i<k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    
    // step 2: fetch element from stack and push it into queue
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    
    // step 3: fetch first n-k from start of queue(pop) and push it back to back of queue(push)
    int t = q.size()-k;
    while(t--)
    {
        q.push(q.front());
        q.pop();
    }
    
    return q;
    
}