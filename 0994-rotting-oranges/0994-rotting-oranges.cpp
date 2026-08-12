class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,{j,0}});
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second.first;
            int t=q.front().second.second;
            ans=max(ans,t);
            q.pop();
            if(i+1<n && j<m && grid[i+1][j]==1 && !vis[i+1][j]){
                vis[i+1][j]=true;
                grid[i+1][j]=2;
                q.push({i+1,{j,t+1}});
            }
            if(j+1<m && i<n && grid[i][j+1]==1 && !vis[i][j+1]){
                vis[i][j+1]=true;
                grid[i][j+1]=2;
                q.push({i,{j+1,t+1}});
            }
            if(i-1>=0 && j<m && grid[i-1][j]==1 && !vis[i-1][j]){
                vis[i-1][j]=true;
                grid[i-1][j]=2;
                q.push({i-1,{j,t+1}});
            }
            if(j-1>=0 && i<n && grid[i][j-1]==1 && !vis[i][j-1]){
                vis[i][j-1]=true;
                grid[i][j-1]=2;
                q.push({i,{j-1,t+1}});
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return ans;

    }
};