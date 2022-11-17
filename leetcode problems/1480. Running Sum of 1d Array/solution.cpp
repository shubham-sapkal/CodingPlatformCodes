class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int i =1, sum = nums[0];

        while(i < nums.size())
        {
            sum += nums[i];
            nums[i] = sum;
            // sum += nums[i];
            i++;
        }

        return nums;

    }
};