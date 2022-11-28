class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> count;

        int maxi = INT_MIN;

        for(int i=0; i<nums.size(); i++)
        {
            count[nums[i]]++;

            if(count[nums[i]] >= (nums.size()/2))
            {
                maxi = max(maxi, count[nums[i]]);
            }
        }

        for(int i=0; i<nums.size(); i++)
        {
            if(count[nums[i]] == maxi )
            {
                return nums[i];
            }
        }

        return -1;

    }
};