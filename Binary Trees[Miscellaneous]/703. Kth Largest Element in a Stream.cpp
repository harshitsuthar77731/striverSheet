class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pqasc;
    int temp=-1;
    KthLargest(int k, vector<int>& nums) {
        temp= k;
        for(auto x:nums){
            pqasc.push(x);
            if(pqasc.size()>k)
                pqasc.pop();
        }
        
    }
    
    int add(int val) {
        pqasc.push(val);
        if(pqasc.size()>temp)
            pqasc.pop();
        int t = pqasc.top();
        return t;
    }
};
