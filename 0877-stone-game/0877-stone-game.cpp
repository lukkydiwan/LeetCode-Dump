class Solution {
public:
    int ans(vector<int> piles, int i, int j, vector<vector<int>> &dp){
        if(i>j)return 0;
        if(i==j)return piles[i];
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        int f=piles[i]-ans(piles,i+1,j,dp);
        int b=piles[j]-ans(piles,i,j-1,dp);
        return dp[i][j]=max(f,b); 
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(),INT_MAX));
        if(ans(piles,0,piles.size()-1,dp)>0)return true;
        return false;
    }
};