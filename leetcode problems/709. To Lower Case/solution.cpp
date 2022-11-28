class Solution {
public:
    string toLowerCase(string s) {
        
        for(int i=0; i<s.length(); i++)
        {
            if(int(s[i]) >= 65 && int(s[i]) <= 90)
            {
                s[i] = char( int(s[i]) + 32 );
            }
        }

        return s;

    }
};