class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
       unordered_map<int,int>mp;
        for(auto x : nums)
            mp[x]++;
        
        int ans = INT_MIN;
        for(auto x : mp){
            int t = x.first;
            int count = 1;
            while(true){
                if(mp.find(t-1)!=mp.end()){
                    count++;
                    mp.erase(t-1);
                    t--; 
                }
                else
                    break;   
            }
            t = x.first;
            while(true){
                if(mp.find(t+1)!=mp.end()){
                    count++;
                    mp.erase(t+1);
                    t++; 
                }
                else
                    break;   
            }
            ans = max(count,ans);
        }
        return ans;
    }
};
