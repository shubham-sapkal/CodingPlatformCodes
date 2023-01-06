class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> wordList;        

        // splitting the s into word
        stringstream str(s);

        string word;
        int count=0;

        while(str>>word){
            count++;
            wordList.push_back(word);
        }

        if(pattern.size() != count)
        {
            return false;
        }


        unordered_map<char, string> entry;
        unordered_map<string, bool> visited;

        for(int i=0; i<pattern.size(); i++)
        {
            char c = pattern[i];

            // case 1 : if word is visited already for new letter
            if(entry[c] == "" && visited[wordList[i]] == true )
            {
                return false;
            }
            // case 2 : if not visited we will make it visited and assign value as v[i]
            else if(entry[c] == "" )
            {
                entry[c] = wordList[i];
                visited[wordList[i]] = true;
            }
            // case 3 : if value is already assigned so not equal to the word
            else if(entry[c] != wordList[i] ){
                return false;
            }
        }

        return true;
    }
};