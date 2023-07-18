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

void solve(TreeNode<int>* root, vector<int>& v, int lvl){
    if(!root) return;
    if(lvl == v.size()) v.push_back(root->data);
    solve(root->left, v, lvl+1);
    solve(root->right, v, lvl+1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    int lvl = 0;
    vector<int> v;
    solve(root, v, lvl);
    return v;
}