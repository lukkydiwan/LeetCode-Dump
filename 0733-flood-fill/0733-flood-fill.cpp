class Solution {
public:
    void dfs(int i, int j, int colo,vector<vector<int>>& grid,vector<vector<bool>>& vis , int orig){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=true;
        grid[i][j]=colo;
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        for(int k=0; k<4; k++){
            int newR=i+dr[k];
            int newC=j+dc[k];
            if(newR>=0 && newR<n && newC>=0 && newC<m && !vis[newR][newC] && grid[newR][newC]==orig){
                dfs(newR, newC , colo, grid,vis,orig);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        dfs(sr,sc,color,image,vis,image[sr][sc]);
        return image;
    }
};