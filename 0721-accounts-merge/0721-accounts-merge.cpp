class Disjoint {
    vector<int> s,p;
    public:
    Disjoint(int n){
        p.resize(n+1);
        s.resize(n+1);
        for(int i=0; i<=n; i++){
            p[i]=i;
            s[i]=1;
        }
    }
    int findUP(int n){
        if(p[n]==n)return n;
        return p[n]=findUP(p[n]);
    }

    void un(int u,int v){
        int uU=findUP(u);
        int uV=findUP(v);
        if(uU==uV)return ;
        if(s[uU]<s[uV]){
            p[uU]=uV;
            s[uV]+=s[uU];
        }else{
            p[uV]=uU;
            s[uU]+=s[uV];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        Disjoint ds(accounts.size());
        int n=accounts.size();
        unordered_map<string,int> m;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail=accounts[i][j];
                if(m.find(mail)==m.end()){
                    m[mail]=i;
                }else{
                    ds.un(i,m[mail]);

                }
            }
        }
        vector<vector<string>> merged(n);
        for(auto x:m){
            string s=x.first;
            int i=ds.findUP(x.second);
            merged[i].push_back(s);
        }
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(merged[i].size()==0)continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (string mail : merged[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }
        return ans;
    }
};