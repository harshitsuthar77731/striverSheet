 // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        queue<int>q;
        unordered_map<int,int>mp;
        q.push(0);
        while(q.size()>0){
            int temp = q.front();
            q.pop();
            vector<int>tempv = adj[temp];
            mp[temp]++;
            ans.push_back(temp);
            for(auto x:tempv)
            {
                if(mp[x]==0)
                    q.push(x);
                mp[x]++;
            }
        }
        return ans;
    }
};
