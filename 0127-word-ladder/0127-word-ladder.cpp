class Solution {
public:
    int ladderLength(string b, string e, vector<string>& w) {
        int ans=0;
        unordered_set<string> s(w.begin(),w.end());
        queue<pair<string,int>>q;
        q.push({b,1});
        while(!q.empty()){
            auto [word,d]=q.front();
            q.pop();
            if(word==e)return d;
            
            for(int i=0; i<word.size(); i++){
                char orig=word[i];
                for(char c='a'; c<='z'; c++){
                    word[i]=c;
                    if(s.find(word)!=s.end()){
                        q.push({word,d+1});
                        s.erase(word);
                    }
                }
                word[i]=orig;
            }
        }
        return 0;
    }
};