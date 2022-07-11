class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>nge(nums2.size(),-1);
        for(int i=0;i<nums2.size();i++){
            if(st.size()>0){
                while(st.size()>0&&nums2[st.top()]<nums2[i]){
                    nge[st.top()] = nums2[i];
                    st.pop();
                }
            }
            st.push(i);
        }
        
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]] = i; 
        }
        vector<int>ans;
        for(auto x:nums1){
            ans.push_back(nge[mp[x]]);
        }

        return ans;
    }
};
