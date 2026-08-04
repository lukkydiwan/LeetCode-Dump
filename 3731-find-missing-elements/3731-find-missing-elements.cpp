class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int st=nums[0];
        int end=nums.back();
        vector<int> ans;
        unordered_map<int,bool> m;
        for(auto x: nums){
            m[x]=true;
        }
        for(int i=st+1; i<end; i++){
            if(!m[i])ans.push_back(i);
        }
        return ans;
    }
};