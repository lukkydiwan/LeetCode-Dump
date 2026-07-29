class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),1);
        vector<int> hash(nums.size(),1);
        int maxi=1,lastIndex=0;
        for(int i=0; i<nums.size(); i++){
                    hash[i]=i;
            for(int prev=0; prev<i; prev++){
                if(nums[i]%nums[prev]==0 && dp[prev]+1>dp[i]){
                    dp[i]=max(dp[i],1+dp[prev]);
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};