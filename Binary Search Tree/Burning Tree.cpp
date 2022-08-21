class Solution {
  public:
    void fun(Node* root,unordered_map<int,vector<int>>&mp){
        if(root==NULL)
            return;
        if(root->left){
            mp[root->data].push_back(root->left->data);
            mp[root->left->data].push_back(root->data);
        }
        if(root->right){
            mp[root->data].push_back(root->right->data);
            mp[root->right->data].push_back(root->data);
        }
        fun(root->left,mp);
        fun(root->right,mp);
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<int,vector<int>>mp;
        fun(root,mp);
        queue<pair<int,int>>q;
        unordered_map<int,bool>visited;
        q.push({target,0});
        visited[target] = true;
        int maxm = -1;
        while(q.size()>0){
            int node = q.front().first;
            int time = q.front().second;
            maxm = max(maxm,time);
            q.pop();
            for(auto x:mp[node]){
                if(visited[x]==false){
                    q.push({x,time+1});
                    visited[x] = true;
                }
            }
        }
        return maxm;
    }
};
