#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool isBST(BinaryTreeNode<int> *root, int minval, int maxval)
{
    // base case
    if(root == NULL)
    {
        return true;
    }
    
    if(root->data >= minval && root->data <= maxval)
    {
        bool left = isBST(root->left, minval, root->data);
        bool right = isBST(root->right, root->data, maxval);
        return left && right;
    }
    else{
        return false;
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return isBST(root, INT_MIN, INT_MAX);
}