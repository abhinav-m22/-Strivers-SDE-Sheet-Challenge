#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void leafTraversal(TreeNode<int>* root, vector<int>& v){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->data);
            return;
        }
        leafTraversal(root->left, v);
        leafTraversal(root->right, v);
    }

void rightBoundary(TreeNode<int>* root, vector<int>& v){
    if(!root || (!root->left && !root->right)) return;
    if(root->right) rightBoundary(root->right, v);
    else rightBoundary(root->left, v);
    v.push_back(root->data);
}

void leftBoundary(TreeNode<int>* root, vector<int>& v){
    if(!root || (!root->left && !root->right)) return;
    v.push_back(root->data);
    if(root->left) leftBoundary(root->left, v);
    else leftBoundary(root->right, v);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> v;
    if(!root) return v;
    v.push_back(root->data);
    leftBoundary(root->left, v);
    leafTraversal(root->left, v);
    leafTraversal(root->right, v);
    rightBoundary(root->right, v);
    return v;
}