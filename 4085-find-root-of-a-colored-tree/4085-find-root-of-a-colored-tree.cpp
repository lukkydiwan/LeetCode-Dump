class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string co) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        vector<int> out(n+1);
        vector<int> in(n+1);
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            if(co[u]==co[v])return -1;
            if(co[u]=='R'){
                if(co[v]=='W'){
                    adj[v].push_back(u);
                    in[u]++;
                    out[v]++;
                }if(co[v]=='B'){
                    adj[u].push_back(v);
                    in[v]++;
                    out[u]++;
                }
            }
            if(co[u]=='B'){
                if(co[v]=='R'){
                    adj[v].push_back(u);
                    in[u]++;
                    out[v]++;
                }if(co[v]=='W'){
                    adj[u].push_back(v);
                    in[v]++;
                    out[u]++;
                }
            }
            if(co[u]=='W'){
                if(co[v]=='B'){
                    adj[v].push_back(u);
                    in[u]++;
                    out[v]++;
                }if(co[v]=='R'){
                    adj[u].push_back(v);
                    in[v]++;
                    out[u]++;
                }
            }   
        }
        for(int i=0; i<=n; i++){
            if(in[i]>1)return -1;
            if(out[i]>2)return -1;
        }
        for(int i=0; i<=n; i++){
            if(in[i]==0 && out[i]<=2)return i;
        }
        return -1;
        
    }
};