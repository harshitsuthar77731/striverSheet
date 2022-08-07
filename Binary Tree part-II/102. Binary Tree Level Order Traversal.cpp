/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int>>v;
        int temp =1;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        vector<int>tt;
        while(q.size()>0){
            TreeNode* node = q.front().first;
            int lev = q.front().second;
            q.pop();
            if(lev==temp)
                tt.push_back(node->val);
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
        v.push_back(tt);
        return v;
    }
};
