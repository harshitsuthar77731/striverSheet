class Solution {
public:
    unordered_map<int,int>mp;
    bool fun(TreeNode* root, int k){
        if(root==NULL)
            return false;
        if(mp[k-root->val]>0)
            return true;
        mp[root->val]++;
        return fun(root->left,k)||fun(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        return fun(root,k);
    }
};
