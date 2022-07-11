vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int>st;
    vector<int>nse(A.size(),-1);
    for(int i=A.size()-1;i>=0;i--){
        if(st.size()>0){
            while(st.size()>0&&A[st.top()]>A[i]){
                nse[st.top()] = A[i];
                st.pop();
            }
        }
        st.push(i);
    }
    return nse;

}
