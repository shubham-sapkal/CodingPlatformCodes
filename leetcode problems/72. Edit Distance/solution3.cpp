class Solution {
public:

    int minDistance(string a, string b) {

        // vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));

        if(a.size() == 0 )
            return b.size();

        if(b.size() == 0 )
            return a.size();

        vector<int> curr(b.size()+1, 0);
        vector<int> next(b.size()+1, 0);

        for(int j=0; j<b.size(); j++)
        {
            next[j] = b.size() - j;
        }

        // for(int i=0; i<a.size(); i++)
        // {
        //     curr[b.size()] = a.size() - i;
        // }

        for(int i=a.size()-1; i>=0; i--)
        {
            for(int j=b.size()-1; j>=0; j--)
            {
                // important part of base case
                curr[b.size()] = a.size() - i;

                if(a[i] == b[j] ) // match
                {
                    curr[j] = next[j+1];
                }
                else{

                    // insert
                    int insertAns = 1 + curr[j+1];

                    // delete
                    int deleteAns = 1 + next[j];

                    // replace
                    int replaceAns = 1 + next[j+1];

                    int ans = min(insertAns, min(deleteAns, replaceAns));

                    curr[j] = ans;
                }
            }
            next = curr;
        }

        return next[0];

    }
};