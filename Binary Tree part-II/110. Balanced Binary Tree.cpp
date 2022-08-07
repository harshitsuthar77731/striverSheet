class Solution {
public:
    bool flag = true;
    int fun(TreeNode* root){
        if(root==NULL)
            return 0;
        int lh = fun(root->left);
        int rh = fun(root->right);
        if(abs(lh-rh)>1)
            flag = false;
        return max(lh,rh)+1;
     }
    bool isBalanced(TreeNode* root) {
        fun(root);
        return flag;
    }
};
