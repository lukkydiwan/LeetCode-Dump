class Solution {
public:
    bool dfs(int i, vector<int> &vis, vector<int> &pvis, vector<vector<int>>& adj){
        vis[i]=1;
        pvis[i]=1;
        for(auto x: adj[i]){
            if(!vis[x]){
                if(dfs(x,vis,pvis,adj)==true)return true;
            }
            else if(pvis[x])return true;
        }
        pvis[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> ans;
        for(int i=0; i<graph.size(); i++){
            vector<int> vis(n);
            vector<int> pvis(n);
            if(!dfs(i,vis,pvis,graph))ans.push_back(i);
        }
        return ans;
    }
};