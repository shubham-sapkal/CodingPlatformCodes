class Solution {
public:
    bool checkRecord(string s) {
        
        int absentCount = 0;
        int lateCount = 0;

        for(int i=0; i<s.length(); i++)
        {
            char ch = s[i];

            if(ch != 'L')
            {
                lateCount = 0;
            }

            if(ch == 'A')
            {
                absentCount++;
                if(absentCount >= 2)
                    return false;
            }

            if(ch == 'L')
            {
                lateCount++;
                if(lateCount >= 3)
                    return false;
            }
            
        }

        return true;

    }
};