class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        // ans counter and endpoint
        int ans = 1;
        int endpoint = INT_MAX;

        // sorting of points in increasing order of points
        sort(points.begin(), points.end());

        // now traverse and find the non overlaping interval, basically ans
        for(auto x : points)
        {
            int start = x[0];
            int end = x[1];

            if(endpoint < start)
            {
                // new interval with no overlapping
                ans++;
                endpoint = end;
            }
            else{
                endpoint = min(endpoint, end);
            }
        }

        return ans;

    }
};