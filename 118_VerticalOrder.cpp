#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> v;
    if(!root) return v;

    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    map<int, vector<int>> mp;

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        TreeNode<int> * node = it.first;
        int val = it.second;

        mp[val].push_back(node->data);

        if(node->left) q.push({node->left, val-1});
        if(node->right) q.push({node->right, val+1});

    }

    for(auto it : mp){
        vector<int> ans = it.second;
        for(auto i : ans){
            v.push_back(i);
        }
    }

    return v;
}