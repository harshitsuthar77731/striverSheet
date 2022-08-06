if(root==NULL)
            return {};
        map<int,int>mp;
        vector<int>v;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(q.size()>0){
            Node* t = q.front().first;
            int lev = q.front().second;
            q.pop();
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
