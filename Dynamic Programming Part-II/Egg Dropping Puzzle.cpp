 public:
    int dp[201][201];
    int fun(int e,int f){
        // base case
        if(e==1)
            return f;
        if(f==0)
            return 0;
        // memoization
        if(dp[e][f]!=-1)
            return dp[e][f];
        // recursive case
        int mn = INT_MAX;
        for(int k=1;k<=f;k++){
            // we will find mi =n of all the worst case
            // once egg break means decrement both floor and egg another agg did not break means check egg dropping from above
            int temp = 1+max(fun(e-1,k-1),fun(e,f-k));
            mn = min(mn,temp);
        }
        return dp[e][f] = mn;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        memset(dp,-1,sizeof(dp));
        return fun(n,k);
    }
