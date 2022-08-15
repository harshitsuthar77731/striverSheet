class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[2501]={0};
        // dp[0] = 1;
        for(int i=0;i<nums.size();i++){
            int maxm = 0;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                    maxm = max(dp[j],maxm);
            }
            dp[i] =1+maxm;
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++){
           ans = max(ans,dp[i]); 
        }
        return ans;
    }
};
