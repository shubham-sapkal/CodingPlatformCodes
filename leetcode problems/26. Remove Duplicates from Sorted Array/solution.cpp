class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0 ){
            return 0;
        }

        int curr = nums[0];
        int count = 0;

        for(int i=1; i<nums.size(); i++)
        {
            if(nums[count] != nums[i] )
            {
                count++;
                nums[count] = nums[i];
                
            }
        }

        return count+1;
        
    }
};