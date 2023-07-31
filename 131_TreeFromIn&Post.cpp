/************************************************************

   Following is the TreeNode class structure

   class TreeNode<T>
   {
   public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
   };


 ************************************************************/

TreeNode<int> *helper(vector<int> &inorder, vector<int> &postorder, int inS, int inE, int postS, int postE)
{
    if (postS > postE)
    {
        return NULL;
    }
    int rootData = postorder[postE];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPostS = postS;
    int lPostE = lInE - lInS + lPostS;
    int rPostS = lPostE + 1;
    int rPostE = postE - 1;
    int rInS = rootIndex + 1;
    int rInE = inE;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    root->left = helper(inorder, postorder, lInS, lInE, lPostS, lPostE);
    root->right = helper(inorder, postorder, rInS, rInE, rPostS, rPostE);
    return root;
}

TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postorder, vector<int> &inorder)
{
    // Write your code here.
    int n = inorder.size();
    return helper(inorder, postorder, 0, n - 1, 0, n - 1);
}
