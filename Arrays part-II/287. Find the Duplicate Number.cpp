class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;){
            if(nums[i]-1==i)
                i++;
            else{
                if(nums[i]==nums[nums[i]-1]){
                    return nums[i];
                }
                else{
                    swap(nums[i],nums[nums[i]-1]);
                }
            }
        }
        return -1;
    }
};
