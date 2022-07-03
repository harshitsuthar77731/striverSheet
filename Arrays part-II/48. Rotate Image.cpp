class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int arr[21][21];
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix.size();j++){
                arr[j][i] = matrix[matrix.size()-1-i][j];
            }
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix.size();j++){
                matrix[i][j] = arr[i][j];
            }
    }
};
