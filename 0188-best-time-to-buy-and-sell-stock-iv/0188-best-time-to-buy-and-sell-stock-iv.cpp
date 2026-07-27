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
    int maxProfit(int kt, vector<int>& p) {
        vector<vector<vector<int>>> dp(p.size()+1, vector<vector<int>> (2,vector<int> (kt+1,0)));
        for(int i=p.size()-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int k=1; k<=kt; k++){
                    if(buy){
                        dp[i][buy][k]=max(-p[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    }else{
                        dp[i][buy][k]=max(p[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                    }
                }
            }
        }
        return dp[0][1][kt];
    }
};