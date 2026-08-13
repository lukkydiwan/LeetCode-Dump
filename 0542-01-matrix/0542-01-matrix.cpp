class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        queue<tuple<int,int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    ans[i][j]=0;
                    vis[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            auto [i,j,d]=q.front();
            q.pop();
            int dr[]={1,0,-1,0};
            int dc[]={0,-1,0,1};
            for(int k=0; k<4; k++){
                int newR=i+dr[k];
                int newC=j+dc[k];
                if(newR<n && newR>=0 && newC>=0 && newC<m && !vis[newR][newC] && mat[newR][newC]==1){
                    vis[newR][newC]=true;
                    ans[newR][newC]=d+1;
                    q.push({newR,newC,d+1});
                }
            }
        }
        return ans;
    }

};