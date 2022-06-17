class Solution {
private:
    
    bool solve(int a, int b, int target)
    {
        if(a+b == target){
            return true;
        }
         return false;
    }
    
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     
        vector<int> ans;
        
        for(int i = 0; i<nums.size()-1; i++){
            
            for(int j = i+1; j<nums.size(); j++){
                
                if(solve(nums[i], nums[j], target) == true ){
                    ans.push_back(i);
                    ans.push_back(j);
                }
                
            }
            
        }
        
        return ans;
        
    }
};