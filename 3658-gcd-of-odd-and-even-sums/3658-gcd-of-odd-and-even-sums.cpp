class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return __gcd(n*n,((2*n)*(2*n+1)/2)-n*n);
    }
};