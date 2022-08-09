vector<int> Solution::dNums(vector<int> &A, int B) {
    int i =0;
    int j =0;
    unordered_map<int,int>mp;
    vector<int>v;
    while(j<A.size()){
        mp[A[j]]++;
        if(j-i+1==B){
            v.push_back(mp.size());
            int t = A[i];
            mp[t]--;
            if(mp[t]==0)
                mp.erase(t);
            i++;
        }
        j++;
    }
    return v;
}
