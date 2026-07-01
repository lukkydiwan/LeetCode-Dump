class Solution {
public:
    int most(vector<int>& nums, int goal){
        int ans=0,sum=0,l=0,r=0;
        if(goal<0)return 0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return most(nums,goal)-most(nums,goal-1);
    }
};