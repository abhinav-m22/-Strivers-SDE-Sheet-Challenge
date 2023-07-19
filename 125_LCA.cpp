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

TreeNode<int> *lca(TreeNode<int> *root, int x, int y)
{
	if(!root || root->data == x || root->data == y) return root;

    TreeNode<int> * left = lca(root->left, x, y);
    TreeNode<int> * right = lca(root->right, x, y);

    if(!left) return right;
    else if(!right) return left;
    else return root;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y){
    TreeNode<int> *ans = lca(root, x, y);
    return ans->data;
}