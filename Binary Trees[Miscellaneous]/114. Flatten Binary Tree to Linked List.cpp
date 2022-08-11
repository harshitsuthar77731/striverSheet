class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* temp = root;
        while(temp!=NULL){
            if(temp->left){
                TreeNode* ri = temp->right;
                TreeNode* le = temp->left;
                TreeNode* let = temp->left;
                temp->left = NULL;
                while(le->right){
                    le = le->right;
                }
                temp->right = let;
                le->right = ri;
            }
            temp = temp->right;
        }
    }
};
