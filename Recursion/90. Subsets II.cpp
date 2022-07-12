class Solution {
public:
    vector<vector<int>>s;
    void fun(vector<int>& nums,int i,vector<int>temp){
        if(i==nums.size()){
                s.push_back(temp);
            return;
        }
        //recursive case
        temp.push_back(nums[i]);
        fun(nums,i+1,temp); //take
        temp.pop_back();
        while(i+1<nums.size()&&nums[i]==nums[i+1]) i++; // we are skiping equal element
        fun(nums,i+1,temp);//skip
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<int>temp;
        fun(nums,0,temp);
        return s;
    }
};
