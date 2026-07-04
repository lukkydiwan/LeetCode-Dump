class Solution {
public:
    bool canJump(vector<int>& nums) {
        int f=0;
        if(nums.size()==1)return 1;
        vector<int> z;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0)z.push_back(i);
        }
        if(z.size()==0)return 1;
        for(int i=0; i<z.size(); i++){
            int f=0;
            for(int j=z[i]-1; j>=0; j--){
                if(nums[j]+j>z[i])f=1;
                else if(nums[j]+j==nums.size()-1)f=1;
                if(f==1)break;
            }
            if(f==0)return 0;
            
        }
        return 1;

    }
};