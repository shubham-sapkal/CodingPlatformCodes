class Solution {
public:

    int minSwap(vector<int>& nums1, vector<int>& nums2) {

        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        /// dp
        int n = nums1.size();
        // vector<vector<int>> dp(n+1, vector<int>(2,0));

        int swap1 = 0;
        int noswap = 0;

        int currswap = 0;
        int currnoswap = 0;

        for(int index=n-1; index >= 1; index--)
        {
            for(int swapped=1; swapped >= 0; swapped--)
            {

                 int ans = INT_MAX;

                int prev1 = nums1[index-1];
                int prev2 = nums2[index-1];

                // catch
                if(swapped)
                {
                    swap(prev1, prev2);
                }

                // no swap
                if(nums1[index] > prev1 && nums2[index] > prev2)
                {
                    ans = noswap;
                }

                // swap
                if(nums1[index] > prev2 && nums2[index] > prev1)
                {
                    ans = min(ans, 1 + swap1);
                }

                if(swapped)
                    currswap = ans;
                else
                    currnoswap = ans;

            }

            // shifting
            swap1 = currswap;
            noswap = currnoswap;

        }


        return min(swap1, noswap);
    }
};