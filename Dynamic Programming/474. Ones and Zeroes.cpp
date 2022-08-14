class Solution {
public:
    int fun(vector<pair<string,int>>& strs,int ind, int m, int n,vector<vector<vector<int>>>&dp){
        // base case
        
        if(strs.size()<=ind)  // imp condition
            return 0;

        // memoization
        if(dp[ind][m][n]!=-1)
            return dp[ind][m][n];
        
        //recursive case
        int o = strs[ind].second;
        int z = strs[ind].first.size()-strs[ind].second;
        int left = INT_MIN,right = INT_MIN;
        if(m>=z&&n>=o){
            left = 1+fun(strs,ind+1,m-z,n-o,dp);
        }
         right = fun(strs,ind+1,m,n,dp);
        return dp[ind][m][n] = max(left,right);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        vector<pair<string,int>>v;
        for(int i=0;i<strs.size();i++){
            bitset<64>b(strs[i]);
            int t = b.count();
            v.push_back({strs[i],t});
        }
        int t=fun(v,0,m,n,dp);
        if(t==INT_MIN+1)
            return 0;
        return t;
    }
};
