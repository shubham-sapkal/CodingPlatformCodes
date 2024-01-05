class Solution {
public:

    

    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        int time=n;

        for(int index=n-1; index>=0; index--)
        {
            for(int time=index; time>=0; time--){
                // include
                int include = (satisfaction[index] * (time+1)) + dp[index+1][time+1];

                // exclude
                int exclude = dp[index+1][time]; // no dish created so time will be same
                
                dp[index][time] = max(include, exclude);
            }
            
        }

        return dp[0][0];

        
    }
};