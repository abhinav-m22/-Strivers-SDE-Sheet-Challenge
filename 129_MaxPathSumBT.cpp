#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int solve(TreeNode<int>* root, int& ans){
    if(!root) return 0;
    int left = solve(root->left, ans);
    int right = solve(root->right, ans);
    ans = max(ans, left + right + root->val);
    return root->val + max(left, right);
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    int ans = INT_MIN;
    if(!root || !root->left || !root->right) return -1;
    solve(root, ans);
    return ans;
}