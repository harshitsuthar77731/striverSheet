class Solution {
public:
   
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        vector<bool>visited(graph.size(),false);
        for(int i=0;i<graph.size();i++){
            queue<pair<int,int>>q;
            if(visited[i]==false){
                q.push({i,1});
                while(q.size()>0){
                    int node=q.front().first;
                    int parity = q.front().second;
                    q.pop();
                    visited[node] = true;
                    int temp;
                    if(color[node]==-1)
                        color[node]= parity;
                    if(parity==1)
                        temp=0;
                    else
                        temp = 1;
                    for(auto x:graph[node]){
                        if(visited[x]==false){
                            if(color[x]==-1||(color[x]!=-1&&color[x]==temp)){
                                color[x]=temp;
                                q.push({x,temp});
                            }
                            else
                                return false;
                        }
                    }
                   }
                }  
            }
        return true;
    }
};
