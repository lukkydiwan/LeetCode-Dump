class Solution {
public:
    int ans(int i, int buy, vector<int> p, vector<vector<int>> &dp){
        if(i==p.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-p[i]+ans(i+1,0,p,dp) , ans(i+1,1,p,dp));
        }else{
            return dp[i][buy]=max(p[i]+ans(i+1,1,p,dp) , ans(i+1,0,p,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        dp[prices.size()][0]=0;
        dp[prices.size()][1]=0;
        for(int i=prices.size()-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                if(buy){
                    dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }else{
                    dp[i][buy]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};