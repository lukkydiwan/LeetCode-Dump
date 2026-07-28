class Solution {
public:
    int ans(int i, int buy, int fee, vector<int> &p, vector<vector<int>> &dp){
        if(i==p.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-p[i]+ans(i+1,0,fee,p,dp),ans(i+1,1,fee,p,dp));
        }else{
            return dp[i][buy]=max(p[i]-fee+ans(i+1,1,fee,p,dp),ans(i+1,0,fee,p,dp));
        }
    }
    int maxProfit(vector<int>& p, int fee) {
        vector<vector<int>> dp(p.size(),vector<int>(2,-1));
        return ans(0,1,fee,p,dp);
    }
};