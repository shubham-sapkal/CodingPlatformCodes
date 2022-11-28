class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> count;

        for(int i=0; i<nums.size(); i++)
        {
            count[nums[i]]++;
        }

        vector<int> ans;

        for(auto i : count){
            if(i.second > (nums.size()/3))
            {
                ans.push_back(i.first);
            }
        }

        return ans;

    }
};