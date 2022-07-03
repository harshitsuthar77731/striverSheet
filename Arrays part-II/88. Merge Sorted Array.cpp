class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1,j=n-1,t = nums1.size()-1;
        while(i>=0&&j>=0){
            if(i>=0&&nums1[i]>=nums2[j]){
                nums1[t] = nums1[i];
                t--;
                i--;
            }
            else if(j>=0&&nums1[i]<nums2[j]){
                nums1[t] = nums2[j];
                j--;
                t--;
            }
        }
        for(int i=0;i<=j;i++){
            nums1[i] = nums2[i];
        }
    }
};
