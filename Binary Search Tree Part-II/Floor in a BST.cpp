void fun(TreeNode<int> * root, int X,int &ans){
    if(root==NULL)
        return ;
    fun(root->left,X,ans);
    if(root->val<=X)
        ans = root->val;
    fun(root->right,X,ans);
}
int floorInBST(TreeNode<int> * root, int X)
{
    int ans =-1;
    fun(root,X,ans);
    return ans;
}
