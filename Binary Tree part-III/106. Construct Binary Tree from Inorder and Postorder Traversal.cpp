
class Solution {
public:
    TreeNode* fun(vector<int>& inorder, vector<int>& postorder,unordered_map<int,int>&mp,int s,int e,int& ind){
        if(s>e||ind<0)
            return NULL;
        TreeNode* root = new TreeNode(postorder[ind]);
        int i = -1;
        if(mp.find(postorder[ind])!=mp.end())
            i = mp[postorder[ind]];
        ind--;
        // post ->l,r,n so we will create node ->n , r , l;
        root->right = fun(inorder,postorder,mp,i+1,e,ind);
        root->left = fun(inorder,postorder,mp,s,i-1,ind);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        unordered_map<int,int>mp;
        int s = 0,e = n-1,ind = n-1;
        for(int i=0;i<n;i++)
            mp[inorder[i]] = i;
        return fun(inorder,postorder,mp,s,e,ind);
    }
};
