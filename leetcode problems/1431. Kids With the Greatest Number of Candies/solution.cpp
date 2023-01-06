class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int n = candies.size();

        vector<bool> ans(n);

        int maxi = INT_MIN;
        for(int i=0; i<n; i++)
        {
            maxi = max(maxi, candies[i]);
        }

        // ans[0] = true;
       
        for(int i=0; i<n; i++)
        {
            if(candies[i]+extraCandies >= maxi )
            {
                // maxi = candies[i];
                ans[i] = true;
            }
        }

        return ans;

    }
};