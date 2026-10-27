class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string s="";
        
        for(int i=0; i<n; i++){
            s+='.';    
        }
        ans.push_back(s);
        s="";
        for(int i=0; i<n-1; i++){
            s+='#';    
        }
    s+='.';
        for(int i=0; i<m-1; i++){
            ans.push_back(s);
        }
return ans;
    }

};