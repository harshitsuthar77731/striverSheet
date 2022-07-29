vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>v;
        unordered_map<int,int>distsrc;
        for(int i=0;i<V;i++)
            distsrc[i] = INT_MAX;
        distsrc[S] = 0; 
        set<pair<int,int>>sp;
        sp.insert({0,S});
        while(!sp.empty()){
            pair<int,int> pai = *(sp.begin());
            int dist = pai.first;
            int node = pai.second;
            
            sp.erase(sp.begin()); // removing that pair
            for(auto nbr:adj[node]){
                if(dist+nbr[1]<distsrc[nbr[0]]){
                    // cout<<nbr[0]<<" "<<nbr[1]<<endl;
                    auto it = sp.find({distsrc[nbr[0]],nbr[0]});
                    if(it!=sp.end())
                        sp.erase(it);
                    distsrc[nbr[0]] = dist+nbr[1];
                    sp.insert({dist+nbr[1],nbr[0]});
                }
            }
        }
        vector<int>ans(V);
        for(auto x:distsrc)
            ans[x.first] = x.second;
        return ans;
    }
