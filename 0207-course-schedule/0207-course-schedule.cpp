class Solution {
public:
    bool dfs(int i, vector<int> &vis,vector<int> &pathVis ,vector<vector<int>> &adj){
        vis[i]=1;
        pathVis[i]=1;
        for(auto x:adj[i]){
            if(!vis[x]){
                if(dfs(x,vis,pathVis,adj)==true)return true;
            }else if(pathVis[x])return true;
        }
        pathVis[i]=0;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<p.size(); i++){
            adj[p[i][0]].push_back(p[i][1]);
        }
        vector<int> vis(numCourses);
        vector<int> pathVis(numCourses);
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
              if(dfs(i,vis,pathVis,adj))return false;
            }
        }
        return true;
    }
};