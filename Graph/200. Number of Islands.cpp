class Solution {
public:
    void dfs(int x,int y,vector<vector<char>>& grid){
        int i = grid.size()-1;
        int j = grid[0].size()-1;
        if(x>=0&&y>=0&&x<=i&&y<=j&&grid[x][y]=='1'){
            grid[x][y] = 2;
            dfs(x+1,y,grid);
            dfs(x,y+1,grid);
            dfs(x-1,y,grid);
            dfs(x,y-1,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};
