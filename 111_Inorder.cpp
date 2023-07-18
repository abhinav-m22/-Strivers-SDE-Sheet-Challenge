#include <bits/stdc++.h> 
using namespace std;

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
    solve(root->left, v);
    v.push_back(root->data);
    solve(root->right, v);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> v;
    // solve(root, v);
    // return v;
    stack<TreeNode*> s;
    while(true){
        if(root){
            s.push(root);
            root = root->left;
        }
        else{
            if(s.empty()) break;
            root = s.top();
            v.push_back(root->data);
            s.pop();
            root = root->right;
        }
    }
    return v;
}