class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()%2==0){
            string half = s.substr(0,s.size()/2);
            sort(half.begin(), half.end());
            string ans=half;
            reverse(half.begin(),half.end());
            return ans+half;
        }else{
            string half = s.substr(0,s.size()/2);
            sort(half.begin(), half.end());
            string ans=half;
            ans+=s[(s.size()-1)/2];
            reverse(half.begin(),half.end());
            return ans+half;

        }
        return s;
    }
};