class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        vector<int>lse(heights.size(),-1);
        vector<int>rse(heights.size(),heights.size());
        for(int i=0;i<heights.size();i++){
            if(st.size()>0){
                while(st.size()>0&&heights[st.top()]>heights[i]){
                    rse[st.top()] = i;
                    st.pop();
                }
            }
                st.push(i);
            
        }
        for(int i=heights.size()-1;i>=0;i--){
            if(st.size()>0){
                while(st.size()>0&&heights[st.top()]>heights[i]){
                    lse[st.top()] = i;
                    st.pop();
                }
            }
                st.push(i);
            
        }
        int ans = 0;
        for(int i=0;i<heights.size();i++){
            int length = rse[i]-lse[i]-1;
            int bredth = heights[i];
            ans = max(ans,length*bredth);
        }
        return ans;
    }
};
