class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for(int i=0; i<26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {

public:
    TrieNode* root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0'); // null char
    }
    
    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0)
        {
            root->isTerminal = true; // mark last word as terminal node
            return ;
        }
        // assumption - word will be in caps
        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL )
        {
            // present
            child = root->children[index];
        }
        else{
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursive call
        insertUtil(child, word.substr(1));

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root, word);
    }
    
    void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix)
    {
        if(curr->isTerminal)
        {
            temp.push_back(prefix);
//             return ;
        }
        
        for(char ch='a'; ch<= 'z'; ch++)
        {
            TrieNode* next = curr->children[ch-'a'];
            if(next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    
    vector<vector<string>> getSuggestions(string queryStr)
    {
        // prev 
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";
        
        for(int i=0; i<queryStr.length(); i++)
        {
            char lastch = queryStr[i];
            
            prefix.push_back(lastch);
            
            // check for last char 
            TrieNode* curr = prev->children[lastch - 'a'];
            
            // if not found
            if(curr == NULL)
            {
                break;
            }
            
            // if found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            
            output.push_back(temp);
            temp.clear();
            
            prev = curr;
        }
        
        return output;
    }
    
    
    
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    // creation of trie
    Trie *t = new Trie();
    
    // Insert all contact in trie
    for(int i=0; i<contactList.size(); i++)
    {
        string str = contactList[i];
        t->insert(str);
    }
    
    // return ans
    return t->getSuggestions(queryStr);
}