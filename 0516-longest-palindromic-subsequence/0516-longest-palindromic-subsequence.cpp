class Solution {
public:
    int ans(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]=1+ans(i-1,j-1,s1,s2,dp);
        return dp[i][j]=max(ans(i-1,j,s1,s2,dp),ans(i,j-1,s1,s2,dp));
    }
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        vector<vector<int>> dp(s.size(),vector<int>(s1.size(),-1));
        return ans(s.size()-1,s1.size()-1,s,s1,dp);
    }
};