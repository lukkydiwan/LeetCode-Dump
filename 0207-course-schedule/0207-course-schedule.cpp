class Solution {
public:
    // bool dfs(int i, vector<int> &vis,vector<int> &pathVis ,vector<vector<int>> &adj){
    //     vis[i]=1;
    //     pathVis[i]=1;
    //     for(auto x:adj[i]){
    //         if(!vis[x]){
    //             if(dfs(x,vis,pathVis,adj)==true)return true;
    //         }else if(pathVis[x])return true;
    //     }
    //     pathVis[i]=0;
    //     return false;

    // }
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<p.size(); i++){
            adj[p[i][0]].push_back(p[i][1]);
        }
        vector<int> topo;
        vector<int> in(numCourses);
        for(int i=0; i<adj.size(); i++){
            for( auto x:adj[i])in[x]++;
        }
        queue<int> q;
        for(int i=0; i<in.size(); i++){
            if(in[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto x:adj[node]){
                in[x]--;
                if(in[x]==0)q.push(x);
            }
        }
        if(topo.size()==numCourses)return true;
        return false;
    }
};