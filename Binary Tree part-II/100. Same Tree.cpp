class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL)
            return true;
        if((p!=NULL&&q==NULL)||(p==NULL&&q!=NULL))
            return false;
        if(p->val!=q->val)
            return false;
        bool flag1 = isSameTree(p->left,q->left);
        bool flag2 = isSameTree(p->right,q->right);
        return flag1&&flag2;
    }
};
