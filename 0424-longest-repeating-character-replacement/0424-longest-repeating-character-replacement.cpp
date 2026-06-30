class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0,l=0,r=0,maxFreq=1;
        unordered_map<int,int> m;
        while(r<n){
            m[s[r]]++;
            maxFreq=max(maxFreq,m[s[r]]);
            int curr=r-l+1;
            if((r-l+1)-maxFreq>k){
                m[s[l]]--;
                // maxFreq=max(maxFreq,m[s[l]]);
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};