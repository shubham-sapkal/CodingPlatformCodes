class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int, int> dp;

        int ans = 0;

        for(int i=0; i<arr.size(); i++)
        {
            int prevElement = arr[i] - difference;
            int tempAns = 0;

            // if prev element found in dp
            if(dp.count(prevElement))
                tempAns = dp[prevElement];
        
            // curr ans update
            dp[arr[i]] = 1 + tempAns;

            ans = max(ans, dp[arr[i]]);
        }

        return ans;

    }
};