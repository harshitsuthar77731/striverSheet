  void fun(Node* node){
        if(node==NULL)
            return; 
        Node* leftnode = node->left;
        fun(node->left);
        fun(node->right);
        node->left = node->right;
        node->right = leftnode;
    }
    void mirror(Node* node) {
        // code here
        fun(node);
    }
