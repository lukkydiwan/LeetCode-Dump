class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*1LL*9<sum)return "";
        string ans="";
        while(sum>9){
            ans+='9';
            sum-=9;
        }
        ans+=to_string(sum);
        while(ans.size()<num)ans+='0';
        return ans;

    }
};