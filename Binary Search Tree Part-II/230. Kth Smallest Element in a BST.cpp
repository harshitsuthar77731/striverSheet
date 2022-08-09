class Solution {
public:
    void fun(TreeNode* root, int &k,int& ans){
        if(root==NULL)
            return;
        fun(root->left,k,ans);
        k--;
        if(k==0)
            ans = root->val;
        fun(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        fun(root,k,ans);
        return ans;
    }
};
