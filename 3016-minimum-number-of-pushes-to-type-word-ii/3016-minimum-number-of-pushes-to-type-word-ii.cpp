class Solution {
public:
    int minimumPushes(string word) {
        vector<int> alpha(26,0);
        for(int i=0; i<word.size(); i++){
            alpha[word[i]-'a']++;
        }
        sort(alpha.begin(),alpha.end());
        int ans=0;
        int i=25,c=1;
        while(i>=0 && alpha[i]!=0){
            ans+=alpha[i]*((c+7)/8);
            c++;
            i--;
        }
        return ans;
    }
};