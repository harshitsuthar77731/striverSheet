class Solution {
public:
    vector<vector<int>> generate(int nu) {
        vector<vector<int>>v;
        if(nu==1)
            return {{1}};
        v.push_back({1});
        v.push_back({1,1});
        for(int i=3;i<=nu;i++){
            vector<int>pre = v[i-2];
            vector<int>temp;
            temp.push_back(1);
            for(int j=0;j<pre.size()-1;j++){
                temp.push_back(pre[j]+pre[j+1]);
            }
            temp.push_back(1);
            v.push_back(temp);
        }
        return v;
    }
};
