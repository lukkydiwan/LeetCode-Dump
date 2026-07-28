class Solution {
public:
    string smallestPalindrome(string s) {
        map<int,int> m;
        for(auto x:s){
            m[x]++;
        }
        string ans="",real;
        if(s.size()%2==0){
            for(auto x:m){
                for(int i=0; i<x.second/2; i++){
                        ans+=x.first;
                    }
            }
            real=ans;
            reverse(ans.begin(), ans.end());
            real+=ans;
            return real;
        }else{
            char c;
            for(auto x:m){
                if(x.second>=2){
                    for(int i=0; i<x.second/2; i++){
                        ans+=x.first;
                    }
                }
                if(x.second%2==1){
                    c=x.first;
                }
            }
                real=ans;
                real+=c;
                reverse(ans.begin(), ans.end());
                real+=ans;
                return real;
        }
        return s;
    }
};