class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pqmin;
        for(auto x : nums){
            pqmin.push(x);
            if(pqmin.size()>k)
                pqmin.pop();
        }
        return pqmin.top();
    }
};
