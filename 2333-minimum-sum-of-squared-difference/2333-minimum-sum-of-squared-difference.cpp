class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<long long> d(1e5+1,0);
        long long maxi=0,sum=0;
        long long k=k1+k2;
        for(int i=0; i<nums1.size(); i++){
            long long diff=abs(nums1[i]-nums2[i]);
            d[diff]++;
            maxi=max(maxi,diff);
            sum+=diff;
        }
        if(k>sum)return 0;
        for(int i=maxi; i>0&& k>0; i--){
            int c=min(k,d[i]);
            k-=c;
            d[i]-=c;
            d[i-1]+=c;
        }
        long long ans=0;
        for(int i=0; i<=maxi; i++){
            ans+=1LL*i*i*d[i];
        }
        return ans;
    }
};