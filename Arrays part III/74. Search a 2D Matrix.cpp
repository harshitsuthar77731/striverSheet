class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            
            if(target<=matrix[i][matrix[i].size()-1]){
                
                int s = 0;
                int e =matrix[i].size()-1;
                while(s<=e){
                    int mid = (e+(s-e)/2);
                    if(matrix[i][mid]==target){
                        return true;}
                    else if(matrix[i][mid]>target){
                        e = mid-1;
                    }
                    else if(matrix[i][mid]<target)
                    {
                        s = mid+1;
                    }
                }
                return false;
            }
        }
        return false;
    }
};
