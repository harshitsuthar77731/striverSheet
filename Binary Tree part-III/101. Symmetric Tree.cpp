class Solution {
public:
    bool fun(TreeNode* leftnode,TreeNode* rightnode){
        if(leftnode==NULL&&rightnode==NULL)
            return true;
        if((leftnode==NULL&&rightnode!=NULL)||(leftnode!=NULL&&rightnode==NULL))
            return false;
        if(leftnode->val!=rightnode->val)
            return false;
        bool f1 = fun(leftnode->right,rightnode->left);
        bool f2 = fun(leftnode->left,rightnode->right);
        return f1&&f2;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return fun(root->left,root->right);
    }
};
