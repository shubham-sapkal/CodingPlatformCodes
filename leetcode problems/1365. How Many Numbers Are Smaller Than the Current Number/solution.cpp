class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> ans(nums.size());

        for(int i=0; i<nums.size(); i++)
        {
            for(int j=0; j<nums.size(); j++)
            {
                if(i != j && nums[i] > nums[j] )
                {
                    ans[i]++;
                }
            }
        }

        return ans;

    }
};