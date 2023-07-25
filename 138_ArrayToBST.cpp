#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode<int> *solve(vector<int> &nums, int start, int end)
{

    if (start > end)
        return NULL;

    int mid = (start + end) / 2;

    TreeNode<int> *root = new TreeNode<int>(nums[mid]);

    root->left = solve(nums, start, mid - 1);

    root->right = solve(nums, mid + 1, end);

    return root;
}

TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    return solve(arr, 0, n - 1);
}