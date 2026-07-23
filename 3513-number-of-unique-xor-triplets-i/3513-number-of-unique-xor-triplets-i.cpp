class Solution {
public:
    int powe(int n){
        int i=1;
        while(pow(2,i)<=n){
            i++;
        }
        return i;
    }
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()<=2)return nums.size();
        else{
            int power=powe(nums.size());
            return 1+pow(2,power)-1;
        }
    }
};