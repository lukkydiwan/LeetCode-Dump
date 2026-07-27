class Solution {
public:
    int ans(int i, int buy, int k,vector<int> p, vector<vector<vector<int>>> &dp){
        if(k<=0)return 0;
        if(i>=p.size())return 0;
        if(dp[i][buy][k]!=-1)return dp[i][buy][k];
        if(buy){
            return dp[i][buy][k]=max(-p[i]+ans(i+1,0,k,p,dp),ans(i+1,1,k,p,dp));
        }else{
            return dp[i][buy][k]=max(p[i]+ans(i+1,1,k-1,p,dp),ans(i+1,0,k,p,dp));
        }
    }
    int maxProfit(int k, vector<int>& p) {
        vector<vector<vector<int>>> dp(p.size(), vector<vector<int>> (2,vector<int> (k+1,-1)));
        return ans(0,1,k,p,dp);
    }
};