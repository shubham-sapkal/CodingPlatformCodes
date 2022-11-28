class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for(int i=0; i<26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie
{
    public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word)
    {
        // base case
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return ;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // recursive call
        insertUtil(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        for(int i=0; i<str.length(); i++)
        {
            char ch = str[i];
            cout<<"ch = " << ch << endl;

            cout<<"root data = " << root->data << endl;
            cout<<"root child count = " << root->childCount << endl;

            if(root->isTerminal)
            {
                break;
            }

            if(root->childCount == 1)
            {
                ans.push_back(ch);
                int index = ch - 'a';
                cout<<"index = "<<index<<endl;
                root = root->children[index];
            }
            // else if(root->isTerminal)
            // {
            //     break;
            // }
            else{
                break;
            }
        
            

        
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        Trie *t = new Trie();
        
        for(string s : strs)
        {
            t->insert(s);
        }

        string ans="";

        t->lcp(strs[0], ans);

        return ans;
        
    }
};