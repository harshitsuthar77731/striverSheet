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
    static bool cmp(pair<int,int>&p1,pair<int,int>&p2){
        if(p1.first==p2.first)
            return p1.second<p2.second;
        else
            return p1.first<p2.first;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,vector<pair<int,int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(q.size()>0){
            TreeNode* t = q.front().first;
            pair<int,int>co = q.front().second;
            q.pop();
            int x = co.first;
            int y = co.second;
            mp[y].push_back({x,t->val});
            if(t->left)
                q.push({t->left,{x+1,y-1}});
            if(t->right)
                q.push({t->right,{x+1,y+1}});
        }
        for(auto x:mp){
            sort(x.second.begin(),x.second.end(),cmp);
            vector<int>temp;
            for(int i=0;i<x.second.size();i++){
                temp.push_back(x.second[i].second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
