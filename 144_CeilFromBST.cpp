#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

void solve(BinaryTreeNode<int> *root, int x, int& ans){
    if(!root) return;
    if(root->data == x) ans = root->data;
    if(root->data < x) return solve(root->right, x, ans);
    if(root->data > x){
        ans = root->data;
        return solve(root->left, x, ans);
    }
}

int findCeil(BinaryTreeNode<int> *root, int x){
    // Write your code here.
    int ans = -1;
    solve(root, x, ans);
    return ans;
}