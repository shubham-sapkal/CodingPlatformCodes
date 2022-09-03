class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        if(nums.size() == 1){
            return nums[0];
        }
        
        sort(nums.begin(), nums.end());
        
    
        
        // vector<vector<int, b>> isVisited;
        
        int ans = -1;
        
        for(int i=0; i<nums.size(); i++)
        {
            // cout<<"i = " << nums[i] << " "<<endl;
            // cout<<nums[i]<< " == " << nums[i+1] << " : "<< (nums[i] == nums[i+1]) << endl; 
            if(nums[i] == nums[i+1] ){
                 i = i+1;
            }
            else {
                ans = nums[i];
            }
            
        }
        
        
        return ans;
        
    }
};