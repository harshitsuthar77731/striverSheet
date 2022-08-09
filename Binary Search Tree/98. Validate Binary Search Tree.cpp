// inorder always sorted in bst concept
class Solution {
public:
    bool flag =true;
    void fun(TreeNode* root,TreeNode* &pre){
        if(root==NULL)
            return;
        fun(root->left,pre);
        if(pre==NULL){
            pre = root;
        }else{
            if(pre->val>=root->val)
                flag = false;
            pre = root;
        }
        fun(root->right,pre);
        
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = NULL;
        fun(root,pre);
        return flag;
    }
};
