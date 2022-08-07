
// in - > l n r
// pre -> n l r
/* 
    we will use in to find left and right by finding place of node
    and we will use pre to genreate node for tree
*/
class Solution {
public:
    int ind = 0;
    TreeNode* fun(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>&mp,int s,int e){
        if(s>e)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[ind]);
        int temp = -1;
        if(mp.find(preorder[ind])!=mp.end())
            temp = mp[preorder[ind]];
        // we can use map insted of it
        // for(int i=s;i<=e;i++){
        //     if(inorder[i] == preorder[ind]){    
        //         temp = i;
        //         break;
        //     }
        // }
        
        ind++;
        root->left = fun(preorder,inorder,mp,s,temp-1);
        root->right = fun(preorder,inorder,mp,temp+1,e); 
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int s = 0;
        int e = preorder.size()-1;
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return fun(preorder,inorder,mp,s,e);
    }
};
