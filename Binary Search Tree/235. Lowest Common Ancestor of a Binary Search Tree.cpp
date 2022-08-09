
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        if(root->val==p->val||root->val==q->val)
            return root;
        TreeNode* le = lowestCommonAncestor(root->left,p,q);
        TreeNode* ri = lowestCommonAncestor(root->right,p,q);
        if(le&&ri)
            return root;
        if(le)
            return le;
        return ri;
    }
};
