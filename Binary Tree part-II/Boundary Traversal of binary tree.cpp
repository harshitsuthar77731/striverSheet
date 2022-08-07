vector<int>v;
    void left(Node *root){
        if(root==NULL||(root->left==NULL&&root->right==NULL))
            return;
        v.push_back(root->data);
        if(root->left){
            left(root->left);
        }else
            left(root->right);
    }
    void right(Node *root){
        if(root==NULL||(root->left==NULL&&root->right==NULL))
            return;
        if(root->right){
            right(root->right);
        }else
            right(root->left);
        v.push_back(root->data);
    }
    void bottom(Node *root){
        if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL){
            v.push_back(root->data);
            return;
        }
        bottom(root->left);
        bottom(root->right);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        if(root==NULL)
            return {};
        v.push_back(root->data);
        left(root->left);
        bottom(root->left);
        bottom(root->right);
        right(root->right);
        return v;
    }
