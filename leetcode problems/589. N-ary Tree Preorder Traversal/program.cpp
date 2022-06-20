/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void preOrderUtil(Node* root, vector<int> &arr){
        if(!root) return;
        
        arr.push_back(root->val);
        
        for(Node* child: root->children){
            preOrderUtil(child, arr);
        }
    }
    
public:
    vector<int> preorder(Node* root) {
        vector<int> visited;
        
        preOrderUtil(root, visited);
        return visited;
    }
};