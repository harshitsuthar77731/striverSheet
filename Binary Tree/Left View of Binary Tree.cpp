vector<int> leftView(Node *root)
{
    if(root==NULL)
        return {};
   vector<int>v;
   queue<pair<Node *,int>>q;
   q.push({root,1});
   int temp = 1;
   while(q.size()>0){
       Node* t = q.front().first;
       int lev = q.front().second;
       q.pop();
       if(lev == temp){
           v.push_back(t->data);
           temp++;
       }
       if(t->left)
        q.push({t->left,lev+1});
       if(t->right)
        q.push({t->right,lev+1});
       
   }
   return v;
}
