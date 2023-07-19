#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    if(!root) return 0;
    queue<TreeNode<int>*> q;
    q.push(root);

    int ans = 0;
    while(!q.empty()){
        int n = q.size();
        int c = 0;
        while(n--){
            TreeNode<int>* node = q.front();
            q.pop();
            c++;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans = max(ans, c);
    }
    return ans;
}