class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int i=0,j=0,ans=0,maxF=0;
        while(j<nums.size()){
            m[nums[j]]++;
            maxF=max(maxF,m[nums[j]]);
            if(maxF>k){
                while(nums[i]!=nums[j]){
                    m[nums[i]]--;
                    i++;
                }
                m[nums[j]]=maxF=k;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};