class Solution {
public:
    int prod(int n){
        int ans=1;
        while(n>0){
            ans*=n%10;
            n/=10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        int ans=n;
        while(true){
            if(prod(ans)%t==0)return ans;
            else ans++;
        }
        return ans;
    }
};