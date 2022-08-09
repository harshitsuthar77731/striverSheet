/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* fun(TreeNode* root, int val){
        if(root==NULL)
            return NULL;
        if(root->val==val)
            return root;
        TreeNode* le = NULL;
        TreeNode* ri = NULL;
        if(root->val>val)
            le = fun(root->left,val);
        if(root->val<val)
            ri = fun(root->right,val);
        if(le)
            return le;
        if(ri)
            return ri;
        return NULL;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return fun(root,val);
    }
};
