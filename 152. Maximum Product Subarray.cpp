class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int dp[100000]={0};
        dp[0] = 1;
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int maxm = nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)
                swap(max_so_far,min_so_far);
            max_so_far = max(nums[i],nums[i]*max_so_far);
            min_so_far = min(nums[i],nums[i]*min_so_far);
            maxm = max(max_so_far,maxm);
        }
        
        return maxm;
    }
};
