class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        vector<vector<int>> dp(p.size()+1,vector<int>(2,0));
        vector<int> ahead(2,0);
        vector<int> curr(2,0);
        for(int i=p.size()-1; i>=0; i--){
            for(int buy=0; buy<2; buy++){
                if(buy){
                    curr[buy]=max(-p[i]+ahead[0],ahead[1]);
                }else{
                    curr[buy]=max(p[i]-fee+ahead[1],ahead[0]);
                }
            }
            ahead=curr;
        }
        return ahead[1];
    }
};