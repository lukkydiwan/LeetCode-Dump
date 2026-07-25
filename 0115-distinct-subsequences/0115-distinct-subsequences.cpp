class Solution {
public:
    int ans(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(j<0)return 1;
        if(i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=ans(i-1,j-1,s,t,dp)+ans(i-1,j,s,t,dp);
        }else{
            return dp[i][j]=ans(i-1,j,s,t,dp);
        }
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return ans(s.size()-1,t.size()-1,s,t,dp);
    }
};