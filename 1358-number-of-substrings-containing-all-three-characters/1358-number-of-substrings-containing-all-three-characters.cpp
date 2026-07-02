class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        vector<int> a(3,-1);
        for(int i=0; i<s.size(); i++){
            a[s[i]-'a']=i;
            if(a[0]!=-1 && a[1]!=-1 && a[2]!=-1){
                ans+=min({a[0],a[1],a[2]})+1;
            }
        }
        return ans;
    }
};