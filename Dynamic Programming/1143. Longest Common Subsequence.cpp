////////recursion+memoization/////////////
class Solution {
public:
    int dp[1001][1001];
    int fun(int ind1,int ind2,string text1, string text2){
        // base case
        if(ind1<0||ind2<0)
            return 0;
        // memoization
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        //recursion
        int equal = 0,not_equal=0;
        if(text1[ind1]==text2[ind2])
            equal =1+fun(ind1-1,ind2-1,text1,text2);
        not_equal = max(fun(ind1-1,ind2,text1,text2),fun(ind1,ind2-1,text1,text2));
        return dp[ind1][ind2] = max(equal,not_equal);
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return fun(text1.size()-1,text2.size()-1,text1,text2);
    }
};
//////////////Tabular//////////////

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<=text1.size();i++)
            dp[i][0] = 0;
        for(int i=0;i<=text2.size();i++)
            dp[0][i] = 0;
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                int equal = 0,not_equal=0;
                if(text1[i-1]==text2[j-1])
                    equal = 1+dp[i-1][j-1];
                not_equal = max(dp[i-1][j],dp[i][j-1]);
                dp[i][j] = max(equal,not_equal);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
