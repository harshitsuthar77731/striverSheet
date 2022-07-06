class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int>mp;
        int pre[n];
        int ans = 0;
        for(int i=0;i<n;i++){
            if(i==0)
            {    
                pre[i] = A[i];
                mp[pre[i]] = i;
            }
            else{
                pre[i] = pre[i-1]+A[i];
                if(pre[i]==0)
                    ans = max(ans,i+1);
                if(mp.find(pre[i])!=mp.end()){
                    ans = max(i-mp[pre[i]],ans);
                }
                else
                    mp[pre[i]] = i;
            }
        }
        return ans;
    }
};

