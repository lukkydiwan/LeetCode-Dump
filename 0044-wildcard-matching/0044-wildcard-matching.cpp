class Solution {
public:
    bool ans(int i, int j, string s, string p, vector<vector<int>> &dp){
        if(i==0 && j==0) return true;
        if(i==0){
            while(j>0){
                if(p[j-1]!='*')return false;
                j--;
            }
            return true;
        }
        if(j==0)return false;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==p[j-1]){
            return dp[i][j]=ans(i-1,j-1,s,p,dp);
        }else if(p[j-1]=='*'){
            return dp[i][j]=ans(i-1,j,s,p,dp)|| ans(i,j-1,s,p,dp);
        }else if(p[j-1]=='?')return dp[i][j]=ans(i-1,j-1,s,p,dp);
        else return dp[i][j]=0;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        dp[0][0]=true;
        for(int i=1; i<=s.size(); i++){
            dp[i][0]=false;
        }
        for(int j=1; j<=p.size(); j++){
            if(p[j-1]=='*')dp[0][j]=dp[0][j-1];
            else dp[0][j]=false;
        }
        for(int i=1; i<=s.size(); i++){
            for(int j=1; j<=p.size(); j++){
                if(s[i-1]==p[j-1]){
                     dp[i][j]=dp[i-1][j-1];
                }else if(p[j-1]=='*'){
                     dp[i][j]=dp[i-1][j]|| dp[i][j-1];
                }else if(p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                else  dp[i][j]=0;
            }
        }
        return dp[s.size()][p.size()];
    }
};