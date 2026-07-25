class Solution {
public:
    vector<int> ng(vector<int> &a){
        vector<int> ans(a.size());
        ans[a.size()-1]=a.back();
        for(int i=a.size()-2; i>=0; i--){
            ans[i]=max(ans[i+1],a[i]);
        }
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<int> next=ng(prices);
        int ans=0;
        for(int i=0; i<prices.size(); i++){
            if(next[i]!=-1)ans=max(ans,next[i]-prices[i]);
        }
        return ans;
    }
};