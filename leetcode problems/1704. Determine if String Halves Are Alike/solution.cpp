class Solution {
public:
    bool halvesAreAlike(string s) {

        unordered_set<char> dict{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}; 

        int n = s.size();
        int count = 0, i = 0, mid = n/2;
        while(i < mid) {
            if(dict.count(s[i])) 
                ++count;
            ++i;
        }

        while(i < n) {
            if(dict.count(s[i]))
                 --count;
            ++i;
        }

        return count == 0;

    }
};