class Solution {
public:
    int ans(int i, int buy, int c, vector<int> p, vector<vector<vector<int>>> &dp){
        if(c>=2)return 0;
        if(i>=p.size())return 0;
        if(dp[i][buy][c]!=-1)return dp[i][buy][c];
        if(buy){
            return dp[i][buy][c]=max(-p[i]+ans(i+1,0,c,p,dp),ans(i+1,1,c,p,dp));
        }else{
            return dp[i][buy][c]=max(p[i]+ans(i+1,1,c+1,p,dp),ans(i+1,0,c,p,dp));
        }
    }
    int maxProfit(vector<int>& p) {
        vector<vector<vector<int>>> dp(p.size()+1,vector<vector<int>> (2,vector<int>(3,0)));
        for(int i=p.size()-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                for(int c=0; c<2; c++){
                    if(buy){
                        dp[i][buy][c]=max(-p[i]+dp[i+1][0][c],dp[i+1][1][c]);
                    }else{
                        dp[i][buy][c]=max(p[i]+dp[i+1][1][c+1],dp[i+1][0][c]);
                    }
                }
            }
        }
        return dp[0][1][0];
    }
};