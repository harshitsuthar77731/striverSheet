class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        stack<int>st;
        for(auto x : nums)
        {
            if(st.empty())
                st.push(x);
            else{
                if(st.top()!=x)
                    st.push(x);
            }
        }
        int i = st.size();
        for(int t = 0;t<i;t++){
            nums[i-t-1] = st.top();
            st.pop();
        }
        return i;
    }
};
