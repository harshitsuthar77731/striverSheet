class Solution {
public:
    bool dfs(int node,int parity,vector<int>&color,vector<bool>&visited,vector<vector<int>>& graph){
        if(visited[node]==false){
            visited[node] = true;
            if(color[node]==-1){
                color[node] = parity;
                int temp;
                if(parity==1)
                    temp = 0;
                else
                    temp = 1;
                for(auto x:graph[node]){
                    if(color[x] == parity)
                        return false;
                    if(dfs(x,temp,color,visited,graph)==false)
                        return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        vector<bool>visited(graph.size(),false);
        for(int i=0;i<graph.size();i++){
            if(visited[i]==false)
                if(dfs(i,1,color,visited,graph)==false)
                    return false;
        }
        return true;
    }
};
