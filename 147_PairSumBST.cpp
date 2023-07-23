#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

void convert(BinaryTreeNode<int> *root, vector<int> &v) {
  if (root == NULL)
    return;

  convert(root->left, v);
  v.push_back(root->data);
  convert(root->right, v);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int> v;
    convert(root, v);
    // sort(v.begin(), v.end());
    int n = v.size();
    int i = 0, j = n-1;
    while(i < j){
        if(v[i]+v[j]==k){
            return 1;
            i++;
            j--;
        }
        else if(v[i]+v[j]>k){
            j--;
        }
        else{
            i++;
        }
    }
    return 0;
}