class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> m;
        set<int> s;
        for(auto x: arr){
            s.insert(x);
        }
        int r=0;
        for(auto x:s){
            r++;
            m[x]=r;
        }
        vector<int> ans;
        for(int i=0; i<arr.size(); i++){
            ans.push_back(m[arr[i]]);
        }
        return ans;
    }
};