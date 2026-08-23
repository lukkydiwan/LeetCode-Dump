class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> neigh(n);
        for(int i=0; i<n; i++){
            vector<int> d(n,INT_MAX);
            d[i]=0;
            priority_queue<pair<int,int> ,
            vector<pair<int,int>> ,
            greater<pair<int,int>> >pq;
            pq.push({0,i});
            while(!pq.empty()){
                int wt=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(auto x:adj[node]){
                    int dis=x.second;
                    int v=x.first;
                    if(d[v]>wt+dis){
                        d[v]=wt+dis;
                        pq.push({d[v],v});
                    }
                }
            } 

            int c=0;
            for(auto x:d){
                if(x<=k)c++;
            }
            neigh[i]=c;
        }
        int mini=INT_MAX;
        for(auto x:neigh)mini=min(mini,x);
        for(int i=n-1; i>=0; i--){
            if(mini==neigh[i])return i;
        }
        return -1;
    }
};