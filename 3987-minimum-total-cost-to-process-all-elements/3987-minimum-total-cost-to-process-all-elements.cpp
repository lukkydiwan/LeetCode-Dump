class Solution {
public:
    int mod=1000000007;
    // long long inv2 = 500000004LL;
    int sum(int n){
        long long ans=0;
        for(int i=1; i<=n; i++){
            ans+=i;
        }
        ans%=mod;
        return (int)ans;
    }
    int minimumCost(vector<int>& nums, int k) {
        long long c=0,r=k;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>r){
                long long val=((nums[i]-r)+k-1LL)/k;
                c+=val;
                r=k*val+r-nums[i];
            }else{
                r-=nums[i];
            }
        }
        long long n ;
        // return (int)(n * ((n + 1) % mod) % mod * inv2 % mod);
        return sum(c%mod);
    }
};