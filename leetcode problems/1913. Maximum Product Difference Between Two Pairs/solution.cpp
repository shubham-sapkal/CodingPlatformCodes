class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int w = nums[nums.size()-2]; 
        int x = nums[nums.size()-1];
        int y = nums[0];
        int z = nums[1];

        return (w*x)-(y*z);
    }
};