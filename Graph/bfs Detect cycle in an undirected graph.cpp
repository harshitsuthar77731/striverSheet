bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,int>visited;
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                queue<pair<int,int>>q;
                q.push({i,-1});
                while(q.size()>0){
                    int node = q.front().first; 
                    int parent = q.front().second;
                    visited[node]++;
                    q.pop();
                    for(auto x: adj[node]){
                        if(visited[x]==0){
                            q.push({x,node});
                        }
                        else if(x!=parent)
                            return true;
                    }
                }
            }
        }
        return false;
    }
