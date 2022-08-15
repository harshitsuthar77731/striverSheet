class Solution {
public:
    int dp[201][201];
    int fun(int i,int j,int m,int n,vector<vector<int>>& grid){
        if(i==m-1&&j==n-1)
            return grid[i][j];
        if(i>=m||j>=n){
            return 2e4;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down = INT_MAX;
        int right = INT_MAX;
        down = grid[i][j]+fun(i+1,j,m,n,grid);
        right = grid[i][j] + fun(i,j+1,m,n,grid);
        return dp[i][j] = min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,grid.size(),grid[0].size(),grid);
    }
};
