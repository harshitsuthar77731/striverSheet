

///////////recursion +memoization/////////

class Solution{
public:
    int dp[501][501];
    bool is_pal(int i,int j,string &s){
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int fun(int i,int j,string s){
        //base case
        if(i>=j)
            return 0;
        if(is_pal(i,j,s))
            return 0;
        // memoization
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        // recursive case
        int ans = INT_MAX;
        for(int k = i;k<=j-1;k++){
            int temp = fun(i,k,s)+fun(k+1,j,s)+1;
            ans = min(temp,ans);
        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        return fun(0,str.size()-1,str);
    }
};

/////////further optimized //////////

class Solution{
public:
    // optimized
    int dp[501][501];
    bool is_pal(int i,int j,string &s){
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int fun(int i,int j,string s){
        //base case
        if(i>=j)
            return 0;
        if(is_pal(i,j,s))
            return 0;
        // memoization
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        // recursive case
        int ans = INT_MAX;
        for(int k = i;k<=j-1;k++){
            int left,right;
          // we are checking that from i to k if we already got our answer than why to call function again get that value same for k+1 to j
            if(dp[i][k]!=-1)
                left = dp[i][k];
            else
                left = fun(i,k,s);
            if(dp[k+1][j]!=-1)
                right = dp[k+1][j];
            else
                right = fun(k+1,j,s);
            int temp = left+right+1;
            ans = min(temp,ans);
        }
        return dp[i][j] = ans;
    }
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        return fun(0,str.size()-1,str);
    }
};
