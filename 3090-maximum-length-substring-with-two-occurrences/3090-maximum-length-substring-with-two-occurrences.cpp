class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans=0;
        for(int i=0; i<s.size(); i++){
            unordered_map<char,int> m;
            int maxF=0;
            for(int j=i; j<s.size(); j++){
                m[s[j]]++;
                maxF=max(maxF,m[s[j]]);
                if(maxF>2){
                    break;
                }
                else ans=max(ans,j-i+1);
            }    
        }
        return ans;
    }
};