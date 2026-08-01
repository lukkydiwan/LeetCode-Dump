class Solution {
public:
    int ans(int st, int end, vector<int> &nums){
        if(st==end){
            return nums[st];
        }
       int takeL=nums[st]-ans(st+1,end,nums);
       int takeR=nums[end]-ans(st,end-1,nums);
       return max(takeL,takeR);
    }
    bool predictTheWinner(vector<int>& nums) {
        if(nums.size()<=2)return true;
        int p1=ans(0,nums.size()-1,nums);
        return p1>=0;
    }
};