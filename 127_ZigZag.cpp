#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> v;
    if(!root) return v;

    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;
    s1.push(root);

    while(!s1.empty()){
        while(!s1.empty()){
            BinaryTreeNode<int> *temp = s1.top();
            s1.pop();
            v.push_back(temp->data);
            if(temp->left) s2.push(temp->left);
            if(temp->right) s2.push(temp->right);
        }
        while(!s2.empty()){
            BinaryTreeNode<int> *temp = s2.top();
            s2.pop();
            v.push_back(temp->data);
            if(temp->right) s1.push(temp->right);
            if(temp->left) s1.push(temp->left);
        }
    }

    return v;
}
