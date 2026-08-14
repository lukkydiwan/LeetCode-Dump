class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        for(int i=0; i<p.size(); i++){
            adj[p[i][1]].push_back(p[i][0]);
        }
        vector<int>topo;
        queue<int>q;
        vector<int> in(n);
        for(int i=0; i<n; i++){
            for(auto x:adj[i])in[x]++;
        }
        for(int i=0; i<in.size(); i++)if(in[i]==0)q.push(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto x:adj[node]){
                in[x]--;
                if(in[x]==0)q.push(x);
            }
        }
        if(topo.size()==n)return topo;
        return {};

    }
};