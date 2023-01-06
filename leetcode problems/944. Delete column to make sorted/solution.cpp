class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
         
        // finding number of rows
        int rows = strs.size();
        int cols = strs[0].size();

        // counter variable 
        int count = 0;

        // traverse columnb wise and for each row
        for(int i=0; i<cols; i++)
        {
            for(int j=1; j<rows; j++)
            {
                // if previous row as higher value mean not sorted hence increase the vales
                // of ans and break the inner loop for checking next column
                if(strs[j-1][i] > strs[j][i] ){
                    count++;
                    break;
                }
            }
        }

        return count;

    }
};