class Solution {
public:
    vector<int> prime(int n){
        vector<int> ans;
        if(n%2==0)ans.push_back(2);
        while(n%2==0){
            n/=2;
        }
        for(int i=3; i*i<=n; i+=2){
            if(n%i==0)ans.push_back(i);
            while(n%i==0)n/=i;
        }
        if (n > 1) {
            ans.push_back(n);
        }
        return ans;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int i=0,j=0,ans=0,dis=0;
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> freq(maxi+1,0);
        while(j< nums.size()){
            vector<int> fast=prime(nums[j]);
            for(auto x:fast){
               if(freq[x]==0){
                    dis++;
               }
               freq[x]++;
            }
            while(dis>k){
                vector<int> ip=prime(nums[i]);
                for(auto x:ip){
                    freq[x]--;
                    if(freq[x]==0){
                        dis--;
                    }
                }
                i++;
            }
            ans=max(j-i+1,ans);
            j++;
        }
        return ans;
    }
};