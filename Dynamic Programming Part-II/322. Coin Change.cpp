////////recursion + memoization////////

class Solution {
public:
    int dp[13][10001];
    int helper(vector<int>& coins, int amount,int ind){
        if(amount==0)
            return 0;
        if(ind<0)
            return INT_MAX-1;
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        
        int take = INT_MAX,not_take = INT_MAX;
        if(amount>=coins[ind]){
            take = 1+helper(coins,amount-coins[ind],ind);
        }
        not_take = helper(coins,amount,ind-1);
        return dp[ind][amount] = min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans = helper(coins,amount,coins.size()-1);
        if(ans == INT_MAX-1)
            return -1;
        return ans;
    }
};
//////////tabular////////////
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[13][10001];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<=amount;i++)
            dp[0][i] = INT_MAX-1;
        for(int i=0;i<=coins.size();i++)
            dp[i][0] = 0;
        
        for(int i=1;i<=coins.size();i++){
            for(int j=0;j<=amount;j++){
                int take = INT_MAX-1,not_take = INT_MAX-1;
                if(j>=coins[i-1]){
                    take = 1+dp[i][j-coins[i-1]];
                }
                not_take = dp[i-1][j];
                dp[i][j] = min(take,not_take);
            }
        }
            
        if(dp[coins.size()][amount] == INT_MAX-1)
            return -1;
        return dp[coins.size()][amount];
    }
};
