class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxi=2048;
        if(nums.size()<2)return nums.size();
        vector<bool> pair(maxi,false);
        vector<bool> tri(maxi,false);
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                pair[nums[i]^nums[j]]=true;
            }
        }
        for(int i=0; i<maxi; i++){
            if(pair[i]){
                for(int j=0; j<nums.size(); j++){
                    tri[nums[j]^i]=true;
                }
            }
        }
        int c=0;
        for(int i=0; i<maxi ;i++){
            if(tri[i])c++;
        }
        return c;
    }
};