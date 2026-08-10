class Solution {
public:
    long long weightedSum(vector<int>& p, vector<int>& nums) {
        int n=p.size();
        vector<vector<int>> c(n);
        for(int i=1; i<p.size(); i++){
            c[p[i]].push_back(i);
        }
        queue<int> q;
        vector<int> depth(n);
        depth[0]=1;
        int h=1;
        q.push(0);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto x:c[u]){
                depth[x]=depth[u]+1;
                h=max(h,depth[x]);
                q.push(x);
            }
        }
        long long ans=0;
        for(int i=0; i<n; i++){
            ans+=1LL * nums[i]* (h-depth[i]+1);
        }
        return ans;

    }
};