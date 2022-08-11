class Solution {
public:
    void dfs( int i,int j,int sr, int sc,int srccolor, int color,vector<vector<int>>& image){
        if(sr<0||sc<0||sr>=i||sc>=j||image[sr][sc]==color||image[sr][sc]!=srccolor)
            return;
        image[sr][sc] = color;
        dfs(i,j,sr+1,sc,srccolor,color,image);
        dfs(i,j,sr,sc+1,srccolor,color,image);
        dfs(i,j,sr,sc-1,srccolor,color,image);
        dfs(i,j,sr-1,sc,srccolor,color,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int i=image.size(),j = image[0].size();
        dfs(i,j,sr,sc,image[sr][sc],color,image);
        return image;
    }
};
