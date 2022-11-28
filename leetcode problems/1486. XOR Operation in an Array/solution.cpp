class Solution {
public:
    int xorOperation(int n, int start) {

        int ans = 0;

        int i=0;
        while(i < n)
        {
            int curr = start + 2*i;

            ans = ans ^ curr;

            i++;
        }

        return ans;

    }
};