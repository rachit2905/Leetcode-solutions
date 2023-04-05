class Solution {
public:
 bool check(vector<int>&nums,int milf){
        long long xn = 0;
        for(int i=nums.size()-1;i>=0;--i){
            if(nums[i]+xn>milf){
                xn = nums[i]+xn-milf;
            }
            else xn = 0;
        } 
        return xn==0;
    }
    int minimizeArrayValue(vector<int>& nums) {
       int lo = 0,hi = 1e9+1;
       while(lo<hi){
           int milf = (lo+hi)/2;
           if(check(nums,milf)){
               hi = milf;
           }
           else{
               lo = milf+1;
           }
       }
       if(check(nums,lo))return lo;
       return hi;
    }
};