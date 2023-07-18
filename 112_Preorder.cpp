#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void solve(TreeNode* root, vector<int>& v){
    if(!root) return;
    v.push_back(root->data);
    solve(root->left, v);
    solve(root->right, v);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> v;
    // solve(root, v);
    // return v;
    if(!root) return v;
    stack<TreeNode*> s;
    s.push(root);

    while(!s.empty()){
        TreeNode* temp = s.top();
        s.pop();
        v.push_back(temp->data);
        if(temp->right) s.push(temp->right);
        if(temp->left) s.push(temp->left);
    }

    return v;
}