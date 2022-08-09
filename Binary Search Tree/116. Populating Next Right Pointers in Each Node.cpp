class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        Node* temp = root;
        queue<Node*>q;
        q.push(temp);
        while(q.size()>0){
            int t = q.size();
            Node* pre = q.front();
            while(t--){
                pre->next = q.front();
                pre = q.front();
                if(pre->left)
                    q.push(pre->left);
                if(pre->right)
                    q.push(pre->right);
                q.pop();
            }   
            pre->next = NULL;
        }
        return root;
    }
};
