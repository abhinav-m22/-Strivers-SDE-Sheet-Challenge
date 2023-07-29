#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

int dfs(BinaryTreeNode<int>* node){
    if(node){
        int sum = 0;
        sum += dfs(node->left);
        sum += dfs(node->right);
        if (!sum) {
            sum = 1e6;
        }
        node->data = sum;
        return sum;
    }else{
        return 0;
    }
}

void changeTree(BinaryTreeNode < int > * root) {
    dfs(root);
}  