class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>mp;
        for(auto x : nums){
            mp[x]++;
        }
        for(auto x : mp){
            pq.push({x.second,x.first});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int>v;
        while(!pq.empty()){
            pair<int,int>p = pq.top();
            pq.pop();
            v.push_back(p.second);
        }
        return v;
    }
};
