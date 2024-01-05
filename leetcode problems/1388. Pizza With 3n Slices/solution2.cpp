class Solution {
public:


    int maxSizeSlices(vector<int>& slices) {
        
        int k = slices.size();

        vector<vector<int>> dp1(k+2, vector<int>(k+2, 0));
        vector<vector<int>> dp2(k+2, vector<int>(k+2, 0));
       

       // case 1
        for(int index=k-2; index>=0; index--)
        {
            for(int n=1; n<=k/3; n++)
            {
                // take slice
                int include = slices[index] + dp1[index+2][n-1];

                // not take slices
                int exclude = 0 + dp1[index+1][n];

                dp1[index][n] = max(include, exclude);
            }
        }
        int case1 = dp1[0][k/3];

        // case 2
        for(int index=k-1; index>=1; index--)
        {
            for(int n=1; n<=k/3; n++)
            {
                // take slice
                int include = slices[index] + dp2[index+2][n-1];

                // not take slices
                int exclude = 0 + dp2[index+1][n];

                dp2[index][n] = max(include, exclude);
            }
        }  
        int case2 = dp2[1][k/3];

        return max(case1, case2);

    }
};