public:
	int minCoins(int coins[], int n, int target) 
	{ 
	    // Your code goes here
	    int dp[n+1][target+1]; 
        
        // base case initialization
        for(int j=0;j<=target;j++) // when amount =0 then for all n = there will be one sol'n
            dp[0][j] = INT_MAX-1;
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;

        // recursive case updation to top down
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                int take=INT_MAX,not_take=INT_MAX;
                if(coins[i-1]<=j){
                    take = 1+dp[i][j-coins[i-1]];
                }
                not_take = dp[i-1][j];
                dp[i][j] = min(take,not_take);
            }
        }
        if(dp[n][target]+1==INT_MAX)
            return -1;
        return dp[n][target];
	}
