class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxi = INT_MIN;

        for(int i=0; i<nums.size()-1; i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                int n1 = nums[i]-1;
                int n2 = nums[j]-1;

                maxi = max(maxi, n1*n2);
            }
        }

        return maxi;

    }
};