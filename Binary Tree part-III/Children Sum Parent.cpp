 bool flag = true;
    void fun(Node* root){
        if(root==NULL||(root->left==NULL&&root->right==NULL))
            return ;
        int t = root->data;
        int temp = 0;
        if(root->left)
            temp+=root->left->data;
        if(root->right)
            temp+=root->right->data;
        if(root->data!=temp)
            flag = false;
        fun(root->left);
        fun(root->right);
        return ;
    }
    int isSumProperty(Node *root)
    {
     // Add your code here
        fun(root);
        return flag;
    }
