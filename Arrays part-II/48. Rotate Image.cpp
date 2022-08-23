imp link
https://leetcode.com/problems/rotate-image/discuss/1449737/Rotation-90Code-180-270-360-explanation-Inplace-O(1)-Space


// without extra space
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //transpose
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //swap
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                    swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
};


// with extra space

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
