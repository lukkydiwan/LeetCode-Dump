class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int maxi=1;
        for(int i=0;i<nums.size(); i++){
            for(int prev=0; prev<i; prev++){
                if(dp[i]<1+dp[prev] && nums[i]>nums[prev]){
                    dp[i]=dp[prev]+1;
                    maxi=max(maxi,dp[i]);
                }
            }
        }
        return maxi;
    }
};