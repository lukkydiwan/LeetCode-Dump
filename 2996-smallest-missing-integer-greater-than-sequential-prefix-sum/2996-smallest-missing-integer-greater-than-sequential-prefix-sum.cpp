class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0],n=nums.size();
        unordered_map<int,int> m;
        m[nums[0]]++;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[i-1]+1){
                break;
            }
            sum+=nums[i];
        }
        if(m.find(sum)==m.end())return sum;
        while(true){
            sum++;
            if(m.find(sum)==m.end())return sum;
        }
        return -1;
    }
};