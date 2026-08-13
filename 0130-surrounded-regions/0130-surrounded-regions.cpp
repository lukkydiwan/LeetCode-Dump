class Solution {
public:
    void dfs(int i, int j , vector<vector<bool>> &vis, vector<vector<char>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=true;
        int dr[]={1,0,-1,0};
        int dc[]={0,-1,0,1};
        for(int k=0; k<4; k++){
            int newR=i+dr[k];
            int newC=j+dc[k];
            if(newR>=0 && newR<n && newC>=0 && newC<m && !vis[newR][newC] && grid[newR][newC]=='O'){
                dfs(newR,newC,vis,grid);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int row[]={0,n-1};
        int col[]={0,m-1};
        for(int i=0; i<2; i++){
            for(int j=0; j<m; j++){
                if(board[row[i]][j]=='O')dfs(row[i],j,vis,board);
            }
        }
        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++){
                if(board[j][col[i]]=='O')dfs(j,col[i],vis,board);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j]=='O')board[i][j]='X';
            }
        }
        return ;
    }
};