class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(),nums.end());
        int i=1;
        while(true){
            if(s.find(k*i)==s.end())return k*i;
            i++;
        }
        return 0;
    }
};