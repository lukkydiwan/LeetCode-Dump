class Solution {
public:
    int ans(int i, int buy, vector<int> &p, vector<vector<int>> &dp){
        if(i>=p.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-p[i]+ans(i+1,0,p,dp),ans(i+1,1,p,dp));
        }else{
            return dp[i][buy]=max(+p[i]+ans(i+2,1,p,dp),ans(i+1,0,p,dp));
        }
    }
    int maxProfit(vector<int>& p) {
        vector<vector<int>> dp(p.size(),vector<int>(2,-1));
        return ans(0,1,p,dp);
    }
};