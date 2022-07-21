 vector<int>ans;
    unordered_map<int,int>mp;
    void dfs(vector<int> adj[],int val){
        if(mp[val]!=0)
            return;
        ans.push_back(val);
        mp[val]++;
        vector<int>temp = adj[val];
        for(int i=0;i<temp.size();i++)
            dfs(adj,temp[i]);
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        dfs(adj,0);
        return ans;
    }
