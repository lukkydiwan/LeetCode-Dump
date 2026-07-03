class Solution {
public:
    bool checkValidString(string s) {
        int o=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='*')o++;
            else o--;
            if(o<0)return 0;
        }
        o=0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]==')' || s[i]=='*')o++;
            else o--;
            if(o<0)return 0;
        }
        return 1;
    }
};