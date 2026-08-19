class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        if(grid[0][0]==1)return -1;
        q.push({{0,0},1});
        grid[0][0]=1;
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int d=q.front().second;
            q.pop();
            if(i==n-1 && j==m-1)return d;
            for(int dr=-1; dr<=1; dr++){
                for(int dc=-1; dc<=1; dc++){
                    if(dr==0 && dc==0 )continue;
                    int newR=i+dr;
                    int newC=j+dc;
                    if(newR<n && newC<m && newR>=0 && newC>=0 && grid[newR][newC]==0){
                        grid[newR][newC]=1;
                        q.push({{newR,newC},d+1});
                    }
                }
            }

        }
        return -1;
    }
};