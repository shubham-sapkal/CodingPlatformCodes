class Solution {
public:

   

    int minSideJumps(vector<int>& obstacles) {

        int n = obstacles.size() - 1;

        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);

        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for(int currpos = n-1; currpos>=0; currpos--){
            for(int currlane = 1; currlane<=3; currlane++){

                if(obstacles[currpos+1] != currlane){
                    curr[currlane] = next[currlane];
                }
                else{
                    // sideways jump
                    int ans = 1e9;
                    for(int i=1; i<=3; i++){
                        if(currlane != i && obstacles[currpos] != i)
                            ans = min(ans, 1 + next[i]); 
                    }

                    curr[currlane] = ans;
                }
            }

            next = curr;
        }

        return min(next[2], min(1+next[1], 1+next[3]));

    }
};