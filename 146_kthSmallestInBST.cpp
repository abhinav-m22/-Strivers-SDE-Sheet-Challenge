#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void solve(TreeNode<int> *root, int& k, int& ans){
    if(!root) return;
    solve(root->left, k, ans);
    if(k != 0){
        k--;
        ans = root->data;
    }
    solve(root->right, k, ans);
}

int kthSmallest(TreeNode<int> *root, int k)
{
	// if(!root) return -1;
    int ans = 0;
    solve(root, k, ans);
    return ans;


}