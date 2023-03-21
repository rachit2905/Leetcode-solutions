class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        long long co=0;
        for(auto it:nums){
            if(it==0)co++;
            else {ans+=(co*(co+1)/2);co=0;}
        }
        ans+=(co*(co+1)/2);return ans;
    }
};