class Solution {
public:
    int maxProfit(vector<int>& p) {
        
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
       
        for(int i=p.size()-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                for(int c=0; c<2; c++){
                    if(buy){
                        curr[buy][c]=max(-p[i]+after[0][c],after[1][c]);
                    }else{
                        curr[buy][c]=max(p[i]+after[1][c+1],after[0][c]);
                    }
                }
            }
                after=curr;
        }
        return after[1][0];
    }
};