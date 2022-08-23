class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                sort(nums.begin()+i+1,nums.end());
                for(int j = i+1;j<nums.size();j++){
                    if(nums[i]<nums[j]){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
                sort(nums.begin()+i+1,nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end());
    }
};
