vector<int> Solution::solve(vector<vector<int> > &arr) {
    vector<int>v;
        priority_queue<int,vector<int>,greater<int>>pdesc;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++)
                pdesc.push(arr[i][j]);
        }
        while(pdesc.size()>0){
            v.push_back(pdesc.top());
            pdesc.pop();
        }
        return v;
}
