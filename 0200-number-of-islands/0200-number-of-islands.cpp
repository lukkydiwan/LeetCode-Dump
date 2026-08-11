class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int k=0; k<4; k++){
            int newR=i+dr[k];
            int newC=j+dc[k];
            if(newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]=='1' && !vis[newR][newC]){
                dfs(newR,newC, grid,vis);
            }
        }
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(grid.size(),vector<int>(m,0));
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};