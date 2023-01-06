class Solution {
public:
    bool judgeCircle(string moves) {
        
        if(moves.length() == 0)
        {
            return true;
        }

        int i=0, j=0;

        for(int k=0; k<moves.length(); k++)
        {
            char ch = moves[k];

            // up
            if(ch == 'U' )
            {
                i=i-1;
            }
            
            // down
            if(ch == 'D')
            {
                i++;
            }

            // left
            if(ch == 'L')
            {
                j--;
            }

            // right
            if(ch == 'R')
            {
                j++;
            }

        }

        return (i == 0 && j == 0);

    }
};