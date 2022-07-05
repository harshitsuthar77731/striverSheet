class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    
        vector<pair<int,int>>vp;
        for(int i=0;i<nums.size();i++){
            vp.push_back({nums[i],i});
        }
        sort(vp.begin(),vp.end());
        int i = 0;
        int j = nums.size()-1;
        while(i<j){
            if(vp[i].first+vp[j].first==target)
                return {vp[i].second,vp[j].second};
            if(vp[i].first+vp[j].first>target)
                j--;
            if(vp[i].first+vp[j].first<target)
                i++;
        }
        return {};
    }
};
