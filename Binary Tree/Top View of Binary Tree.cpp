vector<int> topView(Node *root)
    {
        //Your code here
        if(root==NULL)
            return {};
        
        vector<int>v;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(q.size()>0){
            Node* t = q.front().first;
            int lev = q.front().second;
            q.pop();
            if(mp.find(lev)==mp.end())
                mp[lev] = t->data;
            if(t->left)
                q.push({t->left,lev-1});
            if(t->right)
                q.push({t->right,lev+1});
        }
        
        for(auto x:mp)
            v.push_back(x.second);
        return v;
    }
