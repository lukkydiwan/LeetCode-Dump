class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        int n=word.size(),i=1;
        while(n>0){
            if(n<=8){
                return ans+n*i;
            }
            else{
                ans+=8*i;
                i++;
                n-=8;
            }

        }
        return ans;

    }
};