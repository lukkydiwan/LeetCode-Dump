class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=0;
        int cnt=0,sum=0;
        unordered_map<int,int> m;
        m[0]=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2!=0)sum++;
            cnt+=m[sum-k];
            m[sum]++;
        }
        return cnt;
    }
};