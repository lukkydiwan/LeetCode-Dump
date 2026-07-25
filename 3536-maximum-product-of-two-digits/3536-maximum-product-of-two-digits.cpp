class Solution {
public:
    vector<int> dig(int n){
    vector<int> digit(10,0);
        while(n>0){
            digit[n%10]++;
            n/=10;
        }
        return digit;
    }
    int maxProduct(int n) {
        vector<int> ans=dig(n);
        int c=0,p=1;
        for(int i=ans.size()-1; i>=0; i--){
            if(ans[i]!=0){
                if(c==1){
                    return p*i;
                }
                if(ans[i]==1){
                    p*=i;
                    c++;
                }else if(ans[i]>=2)return i*i;
            }
        }
            return p;
    }
};