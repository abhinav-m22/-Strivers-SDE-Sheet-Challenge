#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

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

struct myPair
{
    int mini;
    int maxi;
    bool isBST;
    int size;
};
myPair findLargest(TreeNode<int> *root, int &ans)
{
    if (!root)
    {

        return {INT_MAX, INT_MIN, true, 0};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {root->data, root->data, true, 1};
    }
    myPair left = findLargest(root->left, ans);
    myPair right = findLargest(root->right, ans);
    if (left.isBST && right.isBST && left.maxi < root->data &&
        right.mini > root->data)
    {
        ans = max(ans, left.size + right.size + 1);
        myPair ret;
        ret.isBST = true;
        ret.size = left.size + right.size + 1;
        ret.mini = min(left.mini, root->data);
        ret.maxi = max(right.maxi, root->data);
        return ret;
    }
    myPair ret;
    ret.size = max(left.size, right.size);
    ret.isBST = false;
    return ret;
}
int largestBST(TreeNode<int> *root)
{
    int ans = 0;
    myPair res = findLargest(root, ans);
    ans = max(ans, res.size);
    return ans;
}
