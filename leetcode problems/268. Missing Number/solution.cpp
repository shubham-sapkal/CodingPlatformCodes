class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        if( nums[0] == 1)
        {
            return 0;
        }

        if(nums.size() == 1)
        {
            return nums[0]+1;
        }

        

        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i+1] != nums[i]+1)
            {
                return nums[i]+1;
            }
        }

        cout<<"value = " << nums[nums.size()-1]+1;

        

        return nums[nums.size()-1]+1;

    }
};