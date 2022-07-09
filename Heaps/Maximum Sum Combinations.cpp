vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    vector<int>v;
    
    priority_queue<pair<int,pair<int,int>>>pq;
    set<pair<int,int>>st;
    int n = A.size();
    pq.push({A[n-1]+B[n-1],{n-1,n-1}});
    
    while(C--){
        v.push_back(pq.top().first);
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        pq.pop();
        if(i>0&&j>0&&st.find({i-1,j})==st.end()){
            pq.push({A[i-1]+B[j],{i-1,j}});
            st.insert({i-1,j});
        }
         if(i>0&&j>0&&st.find({i,j-1})==st.end()){
            pq.push({A[i]+B[j-1],{i,j-1}});
            st.insert({i,j-1});
        }               
    }
        return v;
    
}
