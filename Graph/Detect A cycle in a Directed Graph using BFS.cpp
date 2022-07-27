class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>>mp;
        for(auto x:pre)
            mp[x[1]].push_back(x[0]);
        vector<int>inorder(nc,0);
        
        for(int i=0;i<nc;i++){    
            for(auto x:mp[i])
                inorder[x]++;
        }
        queue<int>q;
        for(int i=0;i<nc;i++){
            if(inorder[i]==0)
                q.push(i);
        }
        int count = 0;

        while(q.size()>0){
            int t = q.front();
            q.pop();
            if(inorder[t]==0)
                count++;
            for(auto x:mp[t]){
                inorder[x]--;
                if(inorder[x]==0)
                    q.push(x);
            }
        }
        if(count == nc)
            return true;
        return false;
    }
};
