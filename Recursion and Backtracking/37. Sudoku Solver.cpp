class Solution {
public:
    bool flag = false;
    bool is_valid(vector<vector<char>>& board,int r,int c,int num){
        //row check
        for(int i=0;i<9;i++){
            if(board[i][c]==num+'0')
                return false;
        }
        //col check
        for(int i=0;i<9;i++){
            if(board[r][i]==num+'0')
                return false;
        }
        //sub matrix check
        int boxr = (r/3)*3;
        int boxc = (c/3)*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[boxr+i][boxc+j]==num+'0'){
                    return false;
                }
            }
        }
        return true;
    }
    void fun(int row,int col,vector<vector<char>>& board){
        if(row==9){
            flag = true;
            return;
        }
        int nr = 0,nc = 0;
        // assigning next row or col
        if(col==8){
            nr = row+1;
            nc = 0;
        }else{
            nc = col+1;
            nr = row;
        }
        // recursive case
        if(board[row][col]!='.')
            fun(nr,nc,board);
        else{
            for(int i=1;i<=9;i++){
                if(is_valid(board,row,col,i)){
                    board[row][col] = '0'+i;
                    fun(nr,nc,board);
                    if(flag==true){
                        return;
                    }
                    board[row][col]='.';
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        fun(0,0,board);
    }
};
