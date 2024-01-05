class Solution {
public:

    bool check(vector<int> base, vector<int> newBox)
    {
        if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2] )
            return true;
        else 
            return false;
    }

    int LongestSubsequence(int n, vector<vector<int>>& a)
    {
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);

        for(int curr=n-1; curr>=0; curr--)
        {
            for(int prev=curr-1; prev>=-1; prev--)
            {
                // include 
                int include = 0;
                if(prev == -1 || check(a[curr], a[prev]))
                    include = a[curr][2] + nextRow[curr+1];
                
                // exclude
                int exclude = 0 + nextRow[prev+1];

                currRow[prev+1] = max(include, exclude);
            }

            nextRow = currRow;

        }

        return nextRow[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        
        // step 1 : sort all dimensions for evevry cuboids
        for(auto &a : cuboids)
        {
            sort(a.begin(), a.end());
        }

        // step 2 : sort dimensions with respect to the width i.e 0th column
        sort(cuboids.begin(), cuboids.end());

        // step 3 : Use LIS logic
        return LongestSubsequence(cuboids.size(), cuboids);
    }
}; 