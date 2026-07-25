class Solution {
public:
    int ans(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(i==0)return j;
        if(j==0)return i;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==t[j-1])return dp[i][j]=ans(i-1,j-1,s,t,dp);
        else{
            int insert=1+ans(i,j-1,s,t,dp);
            int del=1+ans(i-1,j,s,t,dp);
            int replace=1+ans(i-1,j-1,s,t,dp);
            return dp[i][j]=min({insert,del,replace});
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i=0; i<=word1.size(); i++){
            dp[i][0]=i;
        }
        for(int i=0; i<=word2.size(); i++){
            dp[0][i]=i;
        }
        for(int i=1; i<=word1.size(); i++){
            for(int j=1; j<=word2.size(); j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    int insert=1+dp[i][j-1];
                    int del=1+dp[i-1][j];
                    int replace=1+dp[i-1][j-1];
                     dp[i][j]=min({insert,del,replace});
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};