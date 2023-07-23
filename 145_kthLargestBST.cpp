#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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

void solve(TreeNode<int>* root, int& k, int& ans){
    if(!root) return;
    solve(root->right, k, ans);
    k--;
    if(k == 0){
        ans = root->data;
        return;
    }
    solve(root->left, k, ans);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    if(!root) return -1;
    int ans = -1;
    solve(root, k, ans);
    // if(ans == -1)
    return ans;
}
