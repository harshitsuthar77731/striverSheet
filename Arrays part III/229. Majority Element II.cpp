class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>v;
        int el1 = INT_MAX;
        int el2 = INT_MAX;
        int count1 = 0;
        int count2 = 0;
        for(auto x:nums){
            if(x==el1)
                count1++;
            else if(x==el2)
                count2++;
            else if(count1==0){
                el1 = x;
                count1++;
            }
            else if(count2==0){
                el2 = x;
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for(auto x:nums){
            if(x==el1)
                count1++;
            if(x==el2)
                count2++;
        }
        if(count1>nums.size()/3)
            v.push_back(el1);
        if(count2>nums.size()/3)
            v.push_back(el2);
        return v;
    }
};
