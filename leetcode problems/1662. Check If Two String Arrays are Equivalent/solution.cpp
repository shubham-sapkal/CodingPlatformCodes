class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string temp1="";
        for(string s : word1)
        {
            temp1 += s;
        }

        string temp2="";
        for(string s: word2)
        {
            temp2 += s;
        }

        return temp1 == temp2;

    }
};