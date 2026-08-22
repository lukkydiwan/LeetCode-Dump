class Solution {
public:
    int prod(int n){
        int i=1;
        while(n>0){
            i*=n%10;
            n/=10;
        }
        return i;
    }
    int sum(int n){
        int i=0;
        while(n>0){
            i+=n%10;
            n/=10;
        }
        return i;
    }
    bool checkDivisibility(int n) {
        if(n%(prod(n)+sum(n))==0)return true;
        return false;
    }
};