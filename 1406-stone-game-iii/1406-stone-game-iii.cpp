class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size()+3,0);
        for(int i=stoneValue.size()-1; i>=0; i--){
            int o=stoneValue[i]-dp[i+1];
            int t=INT_MIN,th=INT_MIN;
            if(i+1<stoneValue.size()){
                t=stoneValue[i]+stoneValue[i+1]-dp[i+2];            
            }
            if(i+2<stoneValue.size()){
                th=stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3];
            }
             dp[i]=max({o,t,th});
        }
        int diff=dp[0];
        if(diff>0)return "Alice";
        else if(diff==0)return "Tie";
        return "Bob";
    }
};