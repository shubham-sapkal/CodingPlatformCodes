class Solution {
public:

    int solve(string a, string b)
    {
        vector<int> curr(b.size()+1, 0);
        vector<int> next(b.size()+1, 0);

        for(int i=a.size()-1; i >= 0; i--)
        {
            for(int j=b.size()-1; j>=0; j--)
            {
                int ans = 0;
                if(a[i] == b[j] ){
                    ans = 1 + next[j+1];
                }
                else{
                    ans = max( next[j], curr[j+1] );
                }

                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }

    int longestPalindromeSubseq(string s) {
        
        string rev = s;
        reverse(rev.begin(), rev.end());

        return solve(s, rev);

    }
};