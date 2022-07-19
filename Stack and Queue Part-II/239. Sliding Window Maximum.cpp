class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i =0 ;
        int j = 0;
        vector<int>v;
        int sum = 0;
        deque<int>q;
        while(j<nums.size()){
            while(q.size()>0&&nums[j]>q.back())
                q.pop_back();
            q.push_back(nums[j]);
            
            if(j-i+1==k){
                
                v.push_back(q.front());
                if(q.front()==nums[i])
                    q.pop_front();
                i++;
            }
            j++;
        }
        return v;
    }
};
