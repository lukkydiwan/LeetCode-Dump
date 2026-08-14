class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans=0;
        unordered_map<int,int> m;
        int maxF=0;
        int st=0,end=0;
        while(end<s.size()){
            m[s[end]]++;
            maxF=max(maxF,m[s[end]]);
            if(maxF>2){
                while(s[st]!=s[end]){
                    m[s[st]]--;
                    st++;
                }
                maxF=2;
                m[s[st]]--;
                st++;
            }
            ans=max(ans,end-st+1);
            end++;
        }
        return ans;
    }
};