#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void solve(TreeNode<int> *root, int x, int& ans){
    if(!root) return;
    if(root->val == x) ans = root->val;
    if(root->val > x) return solve(root->left, x, ans);
    if(root->val < x){
        ans = root->val;
        return solve(root->right, x, ans);
    }
}

int floorInBST(TreeNode<int> * root, int x)
{
    // Write your code here.
    int ans = -1;
    solve(root, x, ans);
    return ans;
}