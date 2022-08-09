class Solution {
public:
    TreeNode* fun(vector<int>& nums,int s,int e){
        if(s>e)
            return NULL;
        int mid = s+(e-s)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = fun(nums,s,mid-1);
        root->right = fun(nums,mid+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return fun(nums,0,nums.size()-1);
    }
};
