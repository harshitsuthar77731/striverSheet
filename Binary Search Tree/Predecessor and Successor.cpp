void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==NULL||suc)
        return;
    findPreSuc(root->left,pre,suc,key);
    if(root->key<key)
        pre = root;
    else if(root->key>key&&suc==NULL){
        suc = root;
    }
    findPreSuc(root->right,pre,suc,key);
}
