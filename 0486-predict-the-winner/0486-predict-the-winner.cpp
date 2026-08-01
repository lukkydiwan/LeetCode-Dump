class Solution {
public:
    int ans(int st, int end, vector<int> &nums,vector<vector<int>> &dp){
        if(st==end){
            return nums[st];
        }
        if(dp[st][end]!=INT_MAX)return dp[st][end];
       int takeL=nums[st]-ans(st+1,end,nums,dp);
       int takeR=nums[end]-ans(st,end-1,nums,dp);
       return dp[st][end]=max(takeL,takeR);
    }
    bool predictTheWinner(vector<int>& nums) {
        if(nums.size()<=2)return true;
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),INT_MAX));
        int p1=ans(0,nums.size()-1,nums,dp);
        return p1>=0;
    }
};