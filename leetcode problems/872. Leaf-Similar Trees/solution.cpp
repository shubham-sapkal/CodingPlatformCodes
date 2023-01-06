/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void inorder(TreeNode* root, vector<int> &path)
    {
        // base case
        if(root == NULL)
            return;

        inorder(root->left, path);
        if(root->left == NULL && root->right == NULL)
        {
            path.push_back(root->val);
            return ;
        }
        inorder(root->right, path);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> leaves1;
        inorder(root1, leaves1);

        vector<int> leaves2;
        inorder(root2, leaves2);

        return leaves1 == leaves2;
    }
};