class Solution {
public:
     vector<int> nextSmallestElement(vector<int>& heights, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--)
        {
            int curr = heights[i];
            while( s.top() != -1 &&  heights[s.top()] >= curr)
            {
                s.pop();
            }
            // ans is stack of top
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }
    
    vector<int> prevSmallestElement(vector<int>& heights, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++)
        {
            int curr = heights[i];
            while( s.top() != -1 &&  heights[s.top()] >= curr)
            {
                s.pop();
            }
            // ans is stack of top
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int> next(n);
        next = nextSmallestElement(heights, n);
        
        vector<int> prev(n);
        prev = prevSmallestElement(heights, n);

        int area = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            int len = heights[i];
            
            
            if(next[i] == -1 )
                next[i] = n;
            
            int width = next[i] - prev[i] - 1;
            
            int newArea = len*width;
            
            
            area = max(area, newArea);
        }
        
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        

        int maxi = INT_MIN;

        vector<int> histogram(matrix[0].size(), 0);
        for(int i=0; i<matrix.size(); i++)
        {
            // to create histogram array
            for(int j=0; j<histogram.size(); j++)
            {
                if(matrix[i][j] == '1' )
                    histogram[j]++;
                else
                    histogram[j] = 0;
            }

            maxi = max(maxi, largestRectangleArea(histogram));
        }

        return maxi;

    }
};