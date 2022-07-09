class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        for(int i=0;i<nums.size()-2;i++){
                
                if(i!=0&&nums[i]==nums[i-1])
                    continue;
                if(nums[i]+nums[i+1]>-nums[i+2])
                    break;
                if(nums[i]+nums[nums.size()-1]<-nums[nums.size()-2])
                    continue;
            int s = i+1;
            int e = nums.size()-1;
            while(s<e){
                if(nums[i]+nums[s]+nums[e]==0)
                 {   
                    v.push_back({nums[i],nums[s],nums[e]});
                    s++;
                    while(s<e&&nums[s]==nums[s-1])
                        s++;
                 }
                else if(nums[i]+nums[s]+nums[e]<0)
                    s++;
                else if(nums[i]+nums[s]+nums[e]>0)
                    e--;
            }
        }
        return v;
    }
};
