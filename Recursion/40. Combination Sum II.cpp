class Solution {
public:
      vector<vector<int>>v;
    void fun(vector<int>& can,int ind, int target,int sum,vector<int>&temp){
        
        if(ind<=can.size()&&sum==target){
            v.push_back(temp);
            return;
        }
        
        if(ind==can.size())
            return;
        
        if(sum>target)
            return;
        
        temp.push_back(can[ind]);
        fun(can,ind+1,target,sum+can[ind],temp);
        temp.pop_back();
        //skip
        while(ind+1<can.size()&&can[ind]==can[ind+1])ind++;
        fun(can,ind+1,target,sum,temp);
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
         vector<int>temp;
        fun(candidates,0,target,0,temp);
        return v;
    }
};
