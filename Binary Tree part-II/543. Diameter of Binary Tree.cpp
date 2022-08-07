class Solution {
public:
    int h(TreeNode* root,int &ans){
        if(root==NULL)
            return 0;
        int lh = h(root->left,ans);
        int rh = h(root->right,ans);
        ans = max(lh+rh,ans);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        h(root,ans);
        return ans;
    }
};
