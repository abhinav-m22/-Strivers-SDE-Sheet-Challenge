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

class BSTiterator
{
    public:

    stack<int> s;

    void inorder(TreeNode<int>* root){
        if(!root) return;
        inorder(root->right);
        s.push(root->data);
        inorder(root->left);
        return;
    }

    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        inorder(root);
    }

    int next()
    {
        // write your code here
        if(s.empty()) return -1;
        int z = s.top();
        s.pop();
        return z;
    }

    bool hasNext()
    {
        // write your code here
        if(s.empty()) return 0;
        return 1;
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/