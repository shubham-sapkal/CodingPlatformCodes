class Solution {
public:

    bool isSorted(vector<int> arr)
    {
        return is_sorted(arr.begin(), arr.end());
    }

    void solve(vector<int> &nums, int index, vector<int> output, vector<vector<int>> &ans)
    {   
        // base case
        if(index >= nums.size())
        {
            if( output.size() > 1 && isSorted(output) )
            {
                ans.push_back(output);
            }

            return ;
        }

          // include
        output.push_back(nums[index]);
        solve(nums, index+1, output, ans);
        output.pop_back();

        // exclude
        solve(nums, index+1, output, ans);

      
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<int> output;
        vector<vector<int>> ans;

        solve(nums, 0, output, ans);

        sort(ans.begin(), ans.end());

        ans.erase( unique( ans.begin(), ans.end() ), ans.end() );

        return ans;

    }
};