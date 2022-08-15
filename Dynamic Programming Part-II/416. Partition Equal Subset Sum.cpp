///////////recursion +memoization///////////////
class Solution {
public:
    bool helper(vector<int>& nums,int ind,int t,vector<vector<int>>&dp){
        if(t==0)
            return true;
        if(ind>=nums.size())
            return false;
        if(dp[ind][t]!=-1)
            return dp[ind][t];
        int take = false,not_take = false;
        if(t>=nums[ind]){
            take = helper(nums,ind+1,t-nums[ind],dp);
        }
        not_take = helper(nums,ind+1,t,dp);
        return dp[ind][t] = take||not_take;
    }
    bool canPartition(vector<int>& nums) {
        int t = accumulate(nums.begin(),nums.end(),0);
        if(t%2==1)
            return false;
        t = t/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(t+1,-1));
        // return false;
        return helper(nums,0,t,dp);
    }
};

///////////TABULAR//////////
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int t = accumulate(nums.begin(),nums.end(),0);
        if(t%2==1)
            return false;
        t = t/2;
        int dp[nums.size()+1][t+1];
        // base case
        for(int i=0;i<=t;i++)
            dp[0][i] = false;
        for(int i=0;i<=nums.size();i++)
            dp[i][0] = true;
        
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=t;j++){
                // cout<<i<<" "<<j<<endl;
                int take=false ,not_take = false;
                if(j>=nums[i-1]){
                    take = dp[i-1][j-nums[i-1]];
                }
                not_take = dp[i-1][j];
                dp[i][j] = take||not_take;
            }   
        }   
        return dp[nums.size()][t];
    }
};
