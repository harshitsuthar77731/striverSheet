class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int count = 1;
        for(int i =1;i<nums.size();i++)
        {
            int x = nums[i];
            if(count==0){
                count++;
                major = x;
            }
            else if(x==major)
                count++;
            else 
                count--;
        }
        return major;
    }
};


// method 2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums)
            mp[x]++;
        for(auto x : mp){
            if(x.second>nums.size()/2)
                return x.first;
        }
        return -1;
    }
};
