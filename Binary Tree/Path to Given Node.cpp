 vector<int>ans;
 void fun(TreeNode* A, int B,vector<int>&temp){
    if(A==NULL)
        return;
    if(A->val==B){
        temp.push_back(B);
        ans = temp;
    }
    temp.push_back(A->val);
    fun(A->left,B,temp);
    fun(A->right,B,temp);
    temp.pop_back();
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>temp;
    fun(A,B,temp);
    return ans;
}
