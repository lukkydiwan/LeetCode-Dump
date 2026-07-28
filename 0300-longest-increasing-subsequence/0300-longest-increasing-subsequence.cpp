class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int i=nums.size()-1;i>=0; i--){
            for(int prev=i-1; prev>=-1; prev--){
                int len=dp[i+1][prev+1];
                if(prev==-1 || nums[i]>nums[prev]){
                    len=max(len,1+dp[i+1][i+1]);
                }
                dp[i][prev+1]=len;
            }
        }
        return dp[0][0];
    }
};