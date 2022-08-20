class Solution{
    public:
    void fun(vector<vector<int>> &m, vector<string>&ans,int n,int i,int j,string s){
        if((i==n||j==n-1)&&(i==n-1||j==n)&&m[n-1][n-1]==1)
            ans.push_back(s);
        if(i<0||j<0||i>=n||j>=n||m[i][j]==0)
            return;

        m[i][j] = 0;
        fun(m,ans,n,i+1,j,s+'D');
        fun(m,ans,n,i,j+1,s+'R');
        fun(m,ans,n,i-1,j,s+'U');
        fun(m,ans,n,i,j-1,s+'L');
        m[i][j] = 1;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        string s = "";
        fun(m,ans,n,0,0,s);
        return ans;
        // Your code goes here
    }
};
