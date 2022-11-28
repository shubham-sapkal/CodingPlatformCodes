class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;

        for(int i : nums)
        {
            count[i]++;

            if(count[i] > 1)
            {
                return true;
            }
        }

        return false;
    }
};