class Solution {
public:
    int numTrees(int n) {
        // base case
        if( n <= 1)
            return 1;

        int ans = 0;

        // take i as root node
        for(int i=1; i<=n; i++)
        {
            ans += numTrees(i-1) * numTrees(n-i);
        }

        return ans;
    }
};