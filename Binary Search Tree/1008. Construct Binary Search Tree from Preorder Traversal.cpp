
class Solution {
public:
    TreeNode* fun(vector<int>& preorder,int s,int e,int &ind){
        if(preorder[ind]>e||preorder[ind]<s)
            return NULL;
        TreeNode* root = new TreeNode(preorder[ind]);
        int temp = preorder[ind];
        ind++;
        if(ind<preorder.size()&&preorder[ind]<temp)
          root->left =  fun(preorder,s,temp,ind);
        if(ind<preorder.size()&&preorder[ind]>temp)
          root->right =  fun(preorder,temp,e,ind);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return fun(preorder,INT_MIN,INT_MAX,ind);
    }
};
