
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int>>v;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int temp = 1;
        vector<int>tt;
        while(q.size()>0){
            TreeNode* node = q.front().first;
            int lev = q.front().second;
            q.pop();
            if(lev == temp){
                tt.push_back(node->val);
            }
            else{
                v.push_back(tt);
                tt.clear();
                tt.push_back(node->val);
                temp++;
            }
                if(node->left)
                    q.push({node->left,lev+1});
                if(node->right)
                    q.push({node->right,lev+1});
        }
        int i =0;
        v.push_back(tt);
        for(int i=0;i<v.size();i++){
            if(i%2==1)
                reverse(v[i].begin(),v[i].end());
        }
        return v;
    }
};
