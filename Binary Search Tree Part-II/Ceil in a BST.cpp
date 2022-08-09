void fun(BinaryTreeNode<int> * root, int X,int &ans){
    if(root==NULL)
        return ;
    fun(root->left,X,ans);
    if(root->data>=X&&ans==-1)
        ans = root->data;
    fun(root->right,X,ans);
}
int findCeil(BinaryTreeNode<int> *node, int X){
    int ans =-1;
    fun(node,X,ans);
    return ans;
}
