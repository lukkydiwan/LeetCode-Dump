class Solution {
public:
    bool check(string &s1, string &s2){
        if(s1.size()!=s2.size()+1)return false;
        int i=0,j=0;
        while(i<s1.size()){
            if(s1[i]==s2[j]){
                i++,j++;
            }else{
                i++;
            }
        }
        if(i==s1.size() && j==s2.size())return true;
        return false;
    }
    static bool comp(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        vector<int> dp(words.size(),1);
        int maxi=1,n=words.size();
        sort(words.begin(),words.end(),comp);
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(check(words[i],words[prev]) && dp[i]<1+dp[prev]){
                    dp[i]=1+dp[prev];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};