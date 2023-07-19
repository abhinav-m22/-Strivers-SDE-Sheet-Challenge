#include <bits/stdc++.h>
using namespace std;

template <typename T>
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
};

int height(TreeNode<int> *root) // time complexity = O(n)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameterOfBinaryTree(TreeNode<int> *root) // not a good approach -> time complexity not good
{
    if (root == NULL)
    {
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameterOfBinaryTree(root->left);
    int option3 = diameterOfBinaryTree(root->right);

    return max(option1, max(option2, option3));
}

// T.C. - O(n)
pair<int, int> heightDiameter(TreeNode<int>* root){
    if(!root){
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh+rh, max(ld, rd));

    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

int diameterOfBinaryTree(TreeNode<int> *root){
    if(!root) return 0;
    pair<int, int> p = heightDiameter(root);
    return p.second;
}