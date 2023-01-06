class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> arr1;

        for(int i=0; i<n; i++)
        {
            arr1.push_back(nums[i]);
        }

        vector<int> arr2;
        for(int i=n; i<n+n; i++)
        {
            arr2.push_back(nums[i]);
        }

        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            ans.push_back(arr1[i]);
            ans.push_back(arr2[i]);
        }

        return ans;

    }
};