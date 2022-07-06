int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int>mp;
    int count = 0;
    int x = 0;
    for(int i=0;i<A.size();i++){
            x = x^A[i];
            if(x==B)
                count++;
            int t = x^B;
        if(mp[t]>0){
            count+=mp[t];
        }
            mp[x]++;
    }
    return count;
    
}
