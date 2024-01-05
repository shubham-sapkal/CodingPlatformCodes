class Solution {
public:

    

    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        vector<int> next(n+1, 0);
        vector<int> curr(n+1, 0);

        

        for(int index=n-1; index>=0; index--)
        {
            for(int time=index; time>=0; time--){
                // include
                int include = (satisfaction[index] * (time+1)) + next[time+1];

                // exclude
                int exclude = next[time]; // no dish created so time will be same
                
                curr[time] = max(include, exclude);
            }

            // shifting
            next = curr;
            
        }

        return curr[0];

        
    }
};