class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        stack<int>st;
        for(int i=0;i<in.size();i++){
            if(st.size()==0){
                st.push(in[i][0]);
                st.push(in[i][1]);
            }
            else{
                if(st.top()>in[i][0]&&st.top()>in[i][1])
                    continue;
                else if(st.top()>=in[i][0])
                {
                    st.pop();
                    st.push(in[i][1]);
                }
                else if(st.top()<in[i][0]){
                    st.push(in[i][0]);
                    st.push(in[i][1]);
                }   
            }
        }
        vector<vector<int>>v;
        while(st.size()>0){
            vector<int>temp;
            temp.push_back(st.top());
            st.pop();
            temp.push_back(st.top());
            st.pop();
            reverse(temp.begin(),temp.end());
            v.push_back(temp);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
