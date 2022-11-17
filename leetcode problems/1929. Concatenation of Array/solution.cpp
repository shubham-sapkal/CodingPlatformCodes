class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int i = 0;
        // vector<int> ans = nums;
        int size = nums.size();
        while(i < size)
        {
            nums.push_back(nums[i]);
            i++;
        }

        return nums;
    }
};