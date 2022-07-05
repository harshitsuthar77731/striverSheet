class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4)
            return {};
        set<vector<int>>ans;
        int n = nums.size()-1;
        sort(nums.begin(),nums.end());
        for(int a=0;a<nums.size()-3;a++){
             //additional operation to optimize code
                /*********/
            if(a>0&&nums[a]==nums[a-1])
                continue;
            if((long)nums[a]+(long)nums[a+1]>target-(long)nums[a+2]-(long)nums[a+3])
                break;
            if((long)nums[a]+(long)nums[n]<target-(long)nums[n-1]-(long)nums[n-2])
                continue;
            /*********/
            
            for(int b=a+1;b<nums.size()-2;b++){
                //additional operation to optimize code
                /*********/
                if(b>a+1&&nums[b]==nums[b-1])
                    continue;
                if((long)nums[a]+(long)nums[b]>target-(long)nums[b+1]-(long)nums[b+2])
                    break;
                if((long)nums[b]+(long)nums[a]<target-(long)nums[n-1]-(long)nums[n])
                    continue;
                /*********/
                
                
                int c = b+1;
                int d = nums.size()-1;
                int temp = nums[a]+nums[b];
                while(c<d){
                    if((long)temp==(long)target-(long)nums[c]-(long)nums[d])
                    {
                        ans.insert({nums[a],nums[b],nums[c],nums[d]});
                        c++;
                    }
                    if((long)temp>(long)target-(long)nums[c]-(long)nums[d])
                        d--;
                    if((long)temp<(long)target-(long)nums[c]-(long)nums[d])
                        c++;
                }
            }
        }
        vector<vector<int>>fin;
        for(auto x: ans)
            fin.push_back(x);
        return fin;
        
    }
};
