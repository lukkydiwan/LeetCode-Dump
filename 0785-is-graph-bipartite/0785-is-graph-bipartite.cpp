class Solution {
public:
    bool bfs(int i, vector<vector<int>> &adj, vector<int> &vis){
        queue<int> q;
        vis[i]=0;
        q.push(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x:adj[node]){
                if(vis[x]==-1){
                    q.push(x);
                    vis[x]=(vis[node]==0)?1:0;
                }else if(vis[node]==vis[x]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> vis(adj.size(), -1);
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                if(!bfs(i,adj,vis))return false;
            }
        }
        return true;
    }

};