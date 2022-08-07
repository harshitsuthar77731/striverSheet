class Solution {
public:
    void fun(TreeNode* root){
        if(root==NULL)
            return;
        if(root->left!=NULL)
        {
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode* temp2 = root->right;
            while(temp2->right!=NULL){
                temp2 = temp2->right;
            }
            temp2->right = temp;
        }
        fun(root->right);
    }
    void flatten(TreeNode* root) {
        fun(root);
    }
};
