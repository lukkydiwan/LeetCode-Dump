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
        vector<int> next(2,0) , curr(2,0);
        next[0]=0;
        next[1]=0;
        for(int i=prices.size()-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                    curr[1]=max(-prices[i]+next[0],next[1]);
                    curr[0]=max(prices[i]+next[1],next[0]);
            }
            next=curr;
        }
        return next[1];
    }
};