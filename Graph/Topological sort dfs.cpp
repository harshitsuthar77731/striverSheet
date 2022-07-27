	vector<int>ans;
	bool visited[10000] ;
	void dfs(int ind,unordered_map<int,vector<int>>&mp){
	    if(visited[ind]==false){
	        visited[ind] = true;
	        
	        for(auto x : mp[ind]){
	            dfs(x,mp);
	        }
	        ans.push_back(ind);
	    }
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    memset(visited,false,sizeof(visited));
	    unordered_map<int,vector<int>>mp;
	    for(int i=0;i<V;i++){
	        mp[i] = adj[i];
	    }
	   for(int i=0;i<V;i++){
	       if(visited[i]==false)
	            dfs(i,mp);
	   }
	   reverse(ans.begin(),ans.end());
	   return ans;
	}
