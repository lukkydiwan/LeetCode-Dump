class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        unordered_map<int,int> m;
        m[0]=1;
        int prefix=0,cnt=0;
        for(int i=0; i<nums.size(); i++){
            prefix+=nums[i];
            cnt+=m[prefix-goal];
            m[prefix]++;
        }
        return cnt;
    }
};