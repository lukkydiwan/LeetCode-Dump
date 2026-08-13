class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=true;
        int dr[]={1,0,-1,0};
        int dc[]={0,-1,0,1};
        for(int k=0; k<4; k++){
            int newR=i+dr[k];
            int newC=j+dc[k];
            if(newR>=0 && newC>=0 && newR<n && newC<m && !vis[newR][newC] && grid[newR][newC]==1){
                dfs(newR,newC,vis,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0; i<n; i++){
            if(grid[i][0]==1){
                dfs(i,0,vis,grid);
            }
        }
        for(int i=0; i<n; i++){
            if(grid[i][m-1]==1){
                dfs(i,m-1,vis,grid);
            }
        }
        for(int j=0; j<m; j++){
            if(grid[0][j]==1){
                dfs(0,j,vis,grid);
            }
        }
        for(int j=0; j<m; j++){
            if(grid[n-1][j]==1){
                dfs(n-1,j,vis,grid);
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]&&grid[i][j]==1)ans++;
            }
        }
        return ans;
    }
};