#include <bits/stdc++.h>
/************************************************************
    Following is the Binary Search Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int> *rec(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q)
{
    if (!root)
        return NULL;
    if (root->data >= p->data && root->data <= q->data)
        return root;
    else if (root->data < p->data && root->data < q->data)
        return rec(root->right, p, q);
    return rec(root->left, p, q);
}

TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *P, TreeNode<int> *Q)
{
    if (P->data < Q->data)
        return rec(root, P, Q);
    return rec(root, Q, P);
}
