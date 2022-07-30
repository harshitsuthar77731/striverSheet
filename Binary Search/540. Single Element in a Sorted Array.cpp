class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //approach
        // in these problem if every element is appeating twice tha means first elemnt is even and second would be at odd place
        int i = 0;
        int j= nums.size()-1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(mid>0&&mid<nums.size()&&(nums[mid]==nums[mid-1]||nums[mid]==nums[mid+1])){
                if(nums[mid]==nums[mid-1]){
                    if((mid-1)%2==0)
                        i = mid+1;
                    else
                        j = mid-1;
                }
                if(nums[mid]==nums[mid+1]){
                    if((mid)%2==0)
                        i = mid+1;
                    else
                        j = mid-1;
                }
                    
            }
             else
               return nums[mid];
        }
               return -1;
               }
};
