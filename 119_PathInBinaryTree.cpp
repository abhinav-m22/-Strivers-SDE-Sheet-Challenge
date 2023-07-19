#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
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

bool getPath(TreeNode<int>* root, vector<int>& v, int x){
    if(!root) return false;
    v.push_back(root->data);

    if(root->data == x) return true;
    if(getPath(root->left, v, x) || getPath(root->right, v, x)) return true;

    v.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> v;
    if(!root) return v;
    getPath(root, v, x);
    return v;
}
