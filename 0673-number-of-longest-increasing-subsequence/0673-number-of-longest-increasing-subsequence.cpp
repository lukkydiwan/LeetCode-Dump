class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        vector<int> cnt(nums.size(),1);
        int maxi=1,n=nums.size();
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(dp[i]<1+dp[prev] && nums[i]>nums[prev]){
                    dp[i]=1+dp[prev];
                    cnt[i]=cnt[prev];
                    maxi=max(maxi,dp[i]);
                }else if(dp[i]==1+dp[prev] && nums[i]>nums[prev]){
                    cnt[i]+=cnt[prev];
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(dp[i]==maxi)ans+=cnt[i];
        }
        return ans;
    }
};