class Solution {
public:
    bool is_safe(vector<string>&grid,int r,int c){
        // up
        int tr = r-1,tc= c;
        for(int i=tr;i>=0;i--){
            if(grid[i][tc]=='Q'){
                return false;
            }
        }
        //diagonal left
        tr = r-1,tc = c-1;
        while(tr>=0&&tc>=0){
            if(grid[tr][tc]=='Q'){
                return false;
            }
            tr--;
            tc--;
        }
        //diagonal right
        tr = r-1,tc = c+1;
        while(tr>=0&&tc<grid.size()){
            if(grid[tr][tc]=='Q'){
                return false;
            }
            tr--;
            tc++;
        }
        return true;        
    }
    
    void fun(int ind,vector<string>&grid,vector<vector<string>>&ans){
        // base case
        if(ind==grid.size()){
            ans.push_back(grid);
            return;
        }
        //recursive case
        for(int i=0;i<grid.size();i++){
            grid[ind][i] = 'Q';
            if(is_safe(grid,ind,i))
                fun(ind+1,grid,ans);
            // backtrack
            grid[ind][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>grid;
        string s = "";
        for(int i=0;i<n;i++)
            s+='.';
        for(int i=0;i<n;i++)
            grid.push_back(s);
        fun(0,grid,ans);
        return ans;
    }
};
