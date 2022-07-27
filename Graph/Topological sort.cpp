	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    unordered_map<int,vector<int>>mp;
	    for(int i=0;i<V;i++){
	        mp[i] = adj[i];
	    }
	   vector<int>inorder(V,0);
	   for(int i=0;i<V;i++){
	       for(auto y:mp[i])
	            inorder[y]++;
	   }
	   queue<int>q;
	   for(int i=0;i<V;i++){
	       if(inorder[i]==0)
	            q.push(i);
	   }
	   vector<int>ans;
	   while(q.size()>0){
	       int t = q.front();
	       q.pop();
	       ans.push_back(t);
	       for(auto x:mp[t]){
	           inorder[x]--;
	           if(inorder[x]==0)
	                q.push(x);
	       }
	   }
	   return ans;
	}
