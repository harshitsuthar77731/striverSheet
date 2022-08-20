class Solution {
public:
    int dp[301];
    bool fun(int ind,string s,unordered_map<string,int>&mp){
        // base case
        if(ind == s.size()){
            return true;
        }
        //memoization
        if(dp[ind]!=-1)
            return dp[ind];
            
        // recursive case
        string temp = "";
        bool ans = false;
        for(int i=ind;i<s.size();i++){
            temp+=s[i];
            if(mp[temp]>0){
              ans |=  fun(i+1,s,mp);
            }
        }
        return dp[ind] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        memset(dp,-1,sizeof(dp));
        for(auto x:wordDict)
            mp[x]++;
        return fun(0,s,mp);
    }
};
