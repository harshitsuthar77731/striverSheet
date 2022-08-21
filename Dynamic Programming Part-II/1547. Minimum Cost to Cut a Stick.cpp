// we run dp on index of cuts vector not on length

class Solution {
public:
    int dp[101][101];
    int fun(int i,int j,int start,int end,vector<int>&cuts){
        if(i>j)
            return 0;
        // memoization
        if(dp[i][j]!=-1)
            return dp[i][j];
        // recursive case
        int ans = INT_MAX;
        for(int ind=i;ind<=j;ind++){
            int temp = fun(i,ind-1,start,cuts[ind],cuts)+fun(ind+1,j,cuts[ind],end,cuts)+end-start;
            ans = min(temp,ans);
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        return fun(0,cuts.size()-1,0,n,cuts);
    }
};
