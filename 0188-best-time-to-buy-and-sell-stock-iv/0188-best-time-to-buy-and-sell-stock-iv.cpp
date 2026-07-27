class Solution {
public:
    
    int maxProfit(int kt, vector<int>& p) {
        vector<vector<int>> after(2,vector<int> (kt+1,0));
        vector<vector<int>> curr(2,vector<int> (kt+1,0));
        for(int i=p.size()-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int k=1; k<=kt; k++){
                    if(buy){
                        curr[buy][k]=max(-p[i]+after[0][k],after[1][k]);
                    }else{
                        curr[buy][k]=max(p[i]+after[1][k-1],after[0][k]);
                    }
                }
            }
            after=curr;
        }
        return after[1][kt];
    }
};