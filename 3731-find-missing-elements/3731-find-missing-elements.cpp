class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // sort(nums.begin(),nums.end()); //nlogn
        int maxi=INT_MIN;
        int mini=INT_MAX;
        unordered_map<int,bool> m;
        for(auto x: nums){
            maxi=max(maxi,x);
            mini=min(mini,x);
            m[x]=true;
        }
        int st=mini;
        int end=maxi;
        vector<int> ans;   
        for(int i=st+1; i<end; i++){
            if(!m[i])ans.push_back(i); //n
        }
        return ans;
    }
};