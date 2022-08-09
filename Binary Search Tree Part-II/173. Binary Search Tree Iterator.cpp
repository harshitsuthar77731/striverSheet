class BSTIterator {
public:
    stack<TreeNode*>st;
    void partialinorder(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            root = root->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        partialinorder(root);
    }
    
    int next() {
        TreeNode* t= st.top();
        st.pop();
        partialinorder(t->right);
        return t->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
