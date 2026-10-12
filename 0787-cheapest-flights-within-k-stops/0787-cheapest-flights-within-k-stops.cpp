class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto x:flights){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<pair<int,int> , int> ,
                        vector<pair<pair<int,int> , int>> ,
                        greater<pair<pair<int,int>,int>>> pq; //{stop ,k ,node}
        pq.push({{0,0},src});
        vector<int> d(n,INT_MAX);
        d[src]=0;
        while(!pq.empty()){
            int stops=pq.top().first.first;
            int dis=pq.top().first.second;
            int node=pq.top().second;
            pq.pop();
            for(auto x:adj[node]){
                int v=x.first;
                int dd=x.second;
                if(stops<=k && dd+dis<d[v]){
                    d[v]=dd+dis;
                    pq.push({{stops+1,d[v]},v});
                }
            }
        }
        if(d[dst]==INT_MAX)return -1;
        return d[dst];
    }
};