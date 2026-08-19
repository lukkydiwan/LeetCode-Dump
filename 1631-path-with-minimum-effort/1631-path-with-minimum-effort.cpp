class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        vector<vector<int>> d(n,vector<int> (m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, 
        vector<pair<int,pair<int,int>>>, 
        greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        d[0][0]=0;
        while(!pq.empty()){
            int diff=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==m-1)return diff;
            int dr[]={1,0,-1,0};
            int dc[]={0,-1,0,1};
            for(int k=0; k<4; k++){
                int newr=i+dr[k];
                int newc=j+dc[k];
                if(newr>=0 && newc>=0 && newr<n && newc<m ){
                    int newE=max(diff, abs(h[i][j]-h[newr][newc]));
                    if(newE<d[newr][newc]){
                        d[newr][newc]=newE;
                        pq.push({newE,{newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};