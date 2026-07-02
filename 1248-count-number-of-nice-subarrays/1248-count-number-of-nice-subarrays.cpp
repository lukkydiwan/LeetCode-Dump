class Solution {
public:
    int most(vector<int> & nums, int k){
        int ans=0,l=0,r=0,sum=0;
        if(k<0)return 0;
        while(r<nums.size()){
            if(nums[r]%2!=0)sum++;
            while(sum>k){
                if(nums[l]%2!=0)sum--;
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return most(nums,k)-most(nums,k-1);
    }
};