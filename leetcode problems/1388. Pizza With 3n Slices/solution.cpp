class Solution {
public:
    int solve(int index, int endIndex, vector<int> &slices, int n, vector<vector<int>> &dp)
    {
        // base case
        if(n == 0 || index > endIndex)
        {
            return 0;
        }

        // checking dp record
        if(dp[index][n] != -1 )
            return dp[index][n];

        // take slice
        int include = slices[index] + solve(index+2, endIndex, slices, n-1, dp);

        // not take slices
        int exclude = 0 + solve(index+1, endIndex, slices, n, dp);

        return dp[index][n] = max(include, exclude);


    }

    int maxSizeSlices(vector<int>& slices) {
        
        int k = slices.size();
        int n = k/3;
        


        // case 1
        vector<vector<int>> dp1(k, vector<int>(k, -1));
        int case1 = solve(0, k-2, slices, k/3, dp1);

        // case 2
        vector<vector<int>> dp2(k, vector<int>(k, -1));
        int case2 = solve(1, k-1, slices, k/3, dp2);

        return max(case1, case2);

    }
};