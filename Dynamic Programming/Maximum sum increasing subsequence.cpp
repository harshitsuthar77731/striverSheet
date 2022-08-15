	public:
	int maxSumIS(int nums[], int n)  
	{  
	    // Your code goes here
	    int dp[n+1] = {0};
	    for(int i=0;i<n;i++){
	        int maxm = 0;
	        
	        for(int j=0;j<i;j++){
	            if(nums[i]>nums[j])
	                maxm = max(maxm,dp[j]);
	        }
	        dp[i] = nums[i]+maxm;
	    }
	    int maxm = 0;
	    for(int i=0;i<n;i++){
	        maxm = max(maxm,dp[i]);
	    }
	    return maxm;
	}  
