class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int> ,
        vector<pair<int,int>> ,
        greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> d(n+1,INT_MAX);
        d[k]=0;
        while(!pq.empty()){
            auto [dis,node]=pq.top();
            pq.pop();
            for(auto x:adj[node]){
                auto [v,w]=x;
                if(d[v]>w+dis){
                    d[v]=w+dis;
                    pq.push({d[v],v});
                }
            }
        }
        int ans=0;
        for(int i=1; i<=n; i++){
            if(d[i]==INT_MAX)return -1;
            ans=max(ans,d[i]);
        }
        return ans;
    }
};