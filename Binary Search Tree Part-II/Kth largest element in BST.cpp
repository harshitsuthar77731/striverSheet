class Solution
{
    public:
    void fun(Node *root, int &K,int &ans){
        if(root==NULL)
            return;
        fun(root->right,K,ans);
        K--;
        if(K==0)
            ans = root->data;
        fun(root->left,K,ans);
    }
    int kthLargest(Node *root, int K)
    {
        int ans = -1;
        fun(root,K,ans);
        return ans;
    }
};
