unordered_map<int,int>visited;
    bool check(vector<int> adj[],int parent,int node){
        visited[node]++;
        for(auto nbr:adj[node]){
            if(visited[nbr]==0){
                bool cyclemila = check(adj,node,nbr);
                if(cyclemila==true)
                    return true;
            }
            else if(nbr!=parent)
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(check(adj,-1,i)==true)
                    return true;
            }
        }
        return false;
    }
