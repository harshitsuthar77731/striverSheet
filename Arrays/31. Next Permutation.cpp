class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int>v;
        int pre = nums[nums.size()-1];
        int ind = -1;
        int temp;
        for(int i=nums.size()-2;i>=0;i--){
            // cout<<nums[i]<<" "<<pre<<endl;
            if(nums[i]<pre){
                temp = nums[i];
                sort(nums.begin()+i,nums.end());
                ind = i;
                if(nums[nums.size()-1]>=temp){
                    for(int j = i ;j<nums.size();j++){
                        
                        if(nums[j]>temp){
                            
                            swap(nums[i],nums[j]);
                            break;
                        }
                    }
                    sort(nums.begin()+i+1,nums.end());
                    break;
                }
                else 
                    swap(nums[i+1],nums[i]);
                
                break;
            }
            pre = nums[i];
        }
        
        if(ind==-1)
            reverse(nums.begin(),nums.end());
       
    }
};
